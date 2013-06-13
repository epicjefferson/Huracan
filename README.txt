El proyecto Hurac�n es una instalaci�n sonora que incorpora
un arduino para recibir data de photoresistores y controlar 
el motor de un organnette con un 'switch' f�sico. El sistema 
utiliza un Raspberry Pi corriendo Pd-Extended para procesar 
la data de los photosensores y  controlar el sistema de sonido.


Info General:
- Raspberry pi - Raspbian OS
- Pd-extended 0.43.3 
- pduino - [arduino] objeto version 0.5beta8
- arduino UNO - Analog Firmata (modificado)


Instrucciones para instalar pd-extended 0.43.3 
para Raspberry Pi en:
http://www.epicjefferson.com/2012/10/raspberry-pi-pd/

El proyecto inicialmente se construcy� con una netbook,
luego se transfiri� todo el sistema a Raspberry Pi.

Originalmente el mechanismo del organnette era un
motor dc luego fue reemplazado por un 'stepper motor' para
mejor control y reducci�n de velocidad. Por eso los 2 archivos
de arduino. Deber�s escoger el m�s apropiado para tu proyecto. 




para m�s informaci�n:
http://www.puredata.info
http://www.raspberrypi.org
http://www.arduino.cc
http://www.epicjefferson.com
