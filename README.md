# DigiSynth
 

![pcb](imgs/pcb.png)

![schematic](imgs/schematic.png)

### What is it ?
This is a MIDI keyboard and synth that features its own analogue sound output
whith a volume level indicator and sound wave type controll

### Why does it exist ?

This is my spin on the starter project since creating a true AC signal from DC was always a fascination for me for years in the context of power inverters.

### How does it Work ?

When the board powers on, a pico 2 gets powered which reads the value of the Capacitive touch Keys, decides what what the DAC should output. Then communicates that with the DAC IC using the I2S Protocol this then creates a signal from 0 to 3.3V which gets amplified into an AC 3.3V signal which then gets buffered through a class AB amplifier th amplify the current that can be drawn from it the in gets output for use with a speaker or something else

A dedicated LED driver ic takes the signal and displays it as bar of leds depending on the volume 

The AC signal is only possible through a dual rail supply which is achieved using an inverting buck-boost converter

### How would I use it ?

Hopefully it should be Plug'n'play. Connection to usb is optional 
One switch decides if midi is enabled the other decides the wave form of the sound played and the potentiometers controll the volume and pitch

Also you obviously need to programm the pico 2 using PlatformIO with the firmware

| ID | Name                             | Quantity | Manufacturer Part    | Supplier | Supplier Part | Price | Link                                               |
|----|----------------------------------|----------|----------------------|----------|---------------|-------|----------------------------------------------------|
| 1  | 220uF                            | 2        | CL32A227MQVNNNE      | LCSC     | C400951       | 0.8   | https://www.lcsc.com/product-detail/C400951.html   |
| 2  | 1uF                              | 5        | MES105J2A-7-50R0     | LCSC     | C333829       | 0.139 | https://www.lcsc.com/product-detail/C333829.html   |
| 3  | 100nF                            | 50       | 178MU0002            | LCSC     | C5632426      | 0.017 | https://www.lcsc.com/product-detail/C5632426.html  |
| 4  | 10uF                             | 5        | ECR2WLK100MLL100016E | LCSC     | C235887       | 0.159 | https://www.lcsc.com/product-detail/C192100.html   |
| 5  | 100uF                            | 5        | RD1J107M0811MPF      | LCSC     | C18214353     | 0.106 | https://www.lcsc.com/product-detail/C18214353.html |
| 6  | 100uF                            | 10       | VT100UF35V34RV0158   | LCSC     | C2887272      | 0.046 | https://www.lcsc.com/product-detail/C2887272.html  |
| 7  | SS14_C47147601                   | 50       | SS14                 | LCSC     | C47147601     | 0.012 | https://www.lcsc.com/product-detail/C47147601.html |
| 8  | 1N4148_C402212                   | 50       | 1N4148               | LCSC     | C402212       | 0.01  | https://www.lcsc.com/product-detail/C402212.html   |
| 9  | HDR-M-2.54_1x2                   | 20       |                      | LCSC     | C124375       | 0.03  | https://www.lcsc.com/product-detail/C124375.html   |
| 10 | 40uH                             | 5        | YDPK0810-400K        | LCSC     | C22395835     | 0.177 | https://www.lcsc.com/product-detail/C22395835.html |
| 11 | GL3528UG01                       | 50       | GL3528UG01           | LCSC     | C51933337     | 0.019 | https://www.lcsc.com/product-detail/C51933337.html |
| 12 | BD139_C49009574                  | 5        | BD139                | LCSC     | C49009574     | 0.091 | https://www.lcsc.com/product-detail/C49009574.html |
| 13 | BD140_C20604                     | 5        | BD140                | LCSC     | C20604        | 0.121 | https://www.lcsc.com/product-detail/C20604.html    |
| 14 | 1MΩ                              | 20       | FMP100JR-52-1M       | LCSC     | C1740216      | 0.039 | https://www.lcsc.com/product-detail/C1740216.html  |
| 15 | 1.2kΩ                            | 100      | CR1/4W-1K2±5%-ST26   | LCSC     | C2894607      | 0.004 | https://www.lcsc.com/product-detail/C2894607.html  |
| 16 | 20kΩ                             | 2        | RK09K1130ACM         | LCSC     | C470290       | 0.651 | https://www.lcsc.com/product-detail/C470290.html   |
| 17 | 12kΩ                             | 50       | MF0W4FF1202A50       | LCSC     | C20625192     | 0.013 | https://www.lcsc.com/product-detail/C20625192.html |
| 18 | 120Ω                             | 20       | RN1WS120ΩFT/BA1      | LCSC     | C385275       | 0.027 | https://www.lcsc.com/product-detail/C385275.html   |
| 19 | 470kΩ                            | 20       | MFR01SF4703A10       | LCSC     | C58698        | 0.013 | https://www.lcsc.com/product-detail/C58698.html    |
| 20 | SS-12F44-G5                      | 5        | SS-12F44-G5          | LCSC     | C136718       | 0.105 | https://www.lcsc.com/product-detail/C136718.html   |
| 21 | SS13D07VG4                       | 20       | SS13D07VG4           | LCSC     | C2681578      | 0.037 | https://www.lcsc.com/product-detail/C2681578.html  |
| 22 | 750Ω                             | 100      | CR1/8W-750Ω±5%-ST52  | LCSC     | C2848523      | 0.004 | https://www.lcsc.com/product-detail/C2848523.html  |
| 23 | LM3915N(XBLW)                    | 1        | LM3915N(XBLW)        | LCSC     | C55109574     | 0.551 | https://www.lcsc.com/product-detail/C55109574.html |
| 24 | CS4344-CZZ                       | 1        | CS4344-CZZR          | LCSC     | C8952         | 1.524 | https://www.lcsc.com/product-detail/C8952.html     |
| 25 | Raspberry Pi Raspberry Pi Pico 2 | 1        | Raspberry Pi Pico 2  | LCSC     | C41407547     | 9.35  | https://www.lcsc.com/product-detail/C41407547.html |
| 26 | 10kΩ                             | 5        | MFP-25BRD52-10K      | LCSC     | C2655488      | 0.236 | https://www.lcsc.com/product-detail/C2655488.html  |
| 27 | TLV2371IDBVR                     | 1        | TLV2371IDBVR         | LCSC     | C55940        | 0.581 | https://www.lcsc.com/product-detail/C55940.html    |
| 28 | LM2576T-ADJ_C194478              | 1        | LM2576T-ADJ          | LCSC     | C194478       | 0.571 | https://www.lcsc.com/product-detail/C194478.html   |
| 29 | 16.3kΩ                           | 50       | MF1/8W-16K3±1%-ST52  | LCSC     | C2903325      | 0.007 | https://www.lcsc.com/product-detail/C2903325.html  |
