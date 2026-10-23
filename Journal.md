Day 1

I'm trying to figure out how I'm going to implement the DAC part of my project, and it seems hard. For true audio, I need to generate an AC signal, not a signal from GND to 5 or 3.3V, but from +3.3 to -3.3V, and for that I'd need a dual rail supply, which I don't know how to make. Also, I need the DAC to generate between 20 Hz and 20 kHz to cover the hearing spectrum, which is difficult with i2c and high precision.

Ok, I guess I'll have to use an inverting buck converter to make -3.3V

I'm not sure if I want to make an aux like for headphones; I'd rather have it just be a +-3.3V signal that can supply 100 mA current or something useful that could drive a small speaker.

Anyway, it's time for a little break since I have to help with carrying the pumpkins for Halloween.

I think an inverting buck converter to make +- 3.3V alongside a parallel DAC will be best
Maybe if it works, a way easier way to make the signal is to make a signal from 0 to 3.3V using a capacitor to remove bias, then use a differential op-amp to amplify the signal.
Of course it would still need a dual rail supply, but then the DAC IC is easier to find

Actually, I don't even need the cap; I just need the analog reference voltage/DC bias

Ok, I hooked the pico and DAC up together and added what will be the capacitive touch keys

Now I have to go to the gym for a few hours.

Differential opamp needs a gain of 2
OK, so now after amplifying once, I can use a class AB amplifier, which draws more current from the signal to amplify it enough to be useful.

I needed to change the gain of the amp to 1.2 to give the ab amplifier headroom

Ok, I finished the inverting buck boost converter after a lot of confusion, but I think the worst is over.
What's left is to lead indicator lights and switches and then make the PCB.
I think it should be okay to get my 3.3V from the pico 2 as long as the current doesn't exceed 1.4A

I have to make sure to add testing pads on voltages that I want to measure

Added volume pitch waveform selectors / potentiometer

I want to add a volume LED display, but I don't have enough GPIOs, so I'll use an LM3915 LED driver IC.

Calculating resistors for r1, I'd need 675 - 1000 Ohm for 20 - 14 mA
for R2 1060 - 1541 ohm to get 3.3V vref

Ok, I think the schematic is done

I think I'm done for today. I made the schematic, and I'm 90% sure it will work
Tomorrow it will be PCB time.

