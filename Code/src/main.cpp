#include <Arduino.h>
#include <TouchyTouch.h>
#include <MIDIUSB.h>

#include <PicoSound_AudioCore.h>
#include <PicoSound_DualCore.h>

enum class MNote { A, As, B, C, Cs, D, Ds, E, F, Fs, G, Gs};

MNote getMNoteFromPin(int pin)
{
  if (pin < 9) return (MNote)(pin + 3);
  if (pin == 9) return MNote::A;
  if (pin == 14) return MNote::As;
  return MNote::B;
}

float getFrequency(MNote MNote, int semi_tone_offset = 0)
{
  return 440.f * pow(2,  ((int)MNote + semi_tone_offset) / 12.f);
}

// C, C#, D, D#, E, F, F#, G, G#, A, A#, B 
const int touch_pins[] = {0,1,2,3,4,5,6,7,8,9,14,15};
const int touch_count = 12;

bool MIDI_enabled = false;
float volume = 1;
int pitch = 0; // semitone offset lowest should be -48 - 175

WaveType signalType = WaveType::WAVE_SINE;
TouchyTouch touches[touch_count];

void playTune(float freq)
{
  SendAudioCommand(CMD_PLAY_CUSTOM, 0, volume * 100, signalType, freq, 0, 10);
}

void noteOn(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOn = {0x09, 0x90 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOn);
}

void noteOff(byte channel, byte pitch, byte velocity) {
  midiEventPacket_t noteOff = {0x08, 0x80 | channel, pitch, velocity};
  MidiUSB.sendMIDI(noteOff);
}


void setup() {
  pinMode(16, INPUT);
  pinMode(17, INPUT);
  pinMode(18, INPUT);
  pinMode(19, INPUT);
  pinMode(27, INPUT);
  pinMode(28, INPUT);

  analogReadResolution(12);

  for (int i = 0; i < touch_count; i++) {
    touches[i].begin( touch_pins[i] );
  }

  MidiUSB.begin();
  MidiUSB.setName("DigiSynth");
}

void loop() {
  for ( int i = 0; i < touch_count; i++) {
    touches[i].update();

    if (touches[i].touched())
      playTune(getFrequency(getMNoteFromPin(touch_pins[i]), pitch));
    
    if (MIDI_enabled && MidiUSB.connected())
    {
      if (touches[i].pressed())
        noteOn(0, (u_char)getMNoteFromPin(touch_pins[i]) + 69 + pitch, 64);
      if (touches[i].released())
        noteOff(0, (u_char)getMNoteFromPin(touch_pins[i]) + 69 + pitch, 64);
    } 
  }

  if (digitalRead(16)) signalType = WaveType::WAVE_SINE;
  if (digitalRead(17)) signalType = WaveType::WAVE_SQUARE;
  if (digitalRead(18)) signalType = WaveType::WAVE_SAWTOOTH;

  MIDI_enabled = digitalRead(19);
  volume = analogRead(27) / 4096.0;
  pitch = roundf(-48.f + analogRead(28) * (223.f / 4096.f));
  
  if (MIDI_enabled && MidiUSB.connected())
    MidiUSB.flush();
}

void setup1() {
  PicoSound_AudioCore_Setup1();
}

void loop1() {
  PicoSound_AudioCore_Loop1();
}