/* Ruler 1         2         3         4         5         6         7        */

/******************************************************************************/
/*              _     _                  _                                    */
/*             | |   (_)                | |                                   */                  
/*    _ __  _   _| |___ _ _ __ ___   ___| |_ _ __ ___                         */
/*   | '_ \| | | | / __| | '_ ` _ \ / _ \ __| '__/ _ \                        */
/*   | |_) | |_| | \__ \ | | | | | |  __/ |_| | | (_) |                       */
/*     | .__/ \__,_|_|___/_|_| |_| |_|\___|\__|_|\___/                        */
/*   | |                                                                      */
/*   |_|                                                                      */
/*	                _       _                                                 */
/*	               | |     (_)                                                */
/*	   __ _ _ __ __| |_   _ _ _ __   ___      _   _ _ __   ___                */
/*	  / _` | '__/ _` | | | | | '_ \ / _ \    | | | | '_ \ / _ \               */
/*	 | (_| | | | (_| | |_| | | | | | (_) |   | |_| | | | | (_) |              */
/*	  \__,_|_|  \__,_|\__,_|_|_| |_|\___/     \__,_|_| |_|\___/               */
/*                                                                            */
/*    Written in 2021 by Camilo Ramirez, <camilo_ramirez@javeriana.edu.co>    */
/*                       Edward Duarte, <edwardduarte@javeriana.edu.co>       */
/*                       David Orozco, <davidorozco@javeriana.edu.co>         */
/*                       Nicolas Pedraza <pedraza_n@javeriana.edu.co>         */
/*                                                                            */
/*                                                                            */
/* Letters created with "Big" font using http://www.network-science.de/ascii/ */
/******************************************************************************/

/******************************************************************************/
/*                                                                            */
/*    Pulsimetro arduino uno provides the cardiac pulse of evereyone.         */
/*                                                                            */
/*    Copyright (C) 2021 Camilo Ramirez                                       */
/*                       Edward Duarte                                        */
/*                       David Orozco                                         */
/*                       Nicolas Pedraza                                      */
/*                                                                            */
/*    This file is part of DC Solver.                                         */
/*                                                                            */
/*    Pulsimetro arduino uno is free software: you can redistribute it        */
/*    and/or modify it under the terms of the GNU General Public License as   */
/*    published by the Free Software Foundation, either version 3 of the      */
/*    License, or (at your option) any later version.                         */
/*                                                                            */
/*    Pulsimetro arduino uno is distributed in the hope that it will be       */
/*    but WITHOUT ANY WARRANTY; without even the implied warranty of          */
/*    useful,MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the    */
/*    GNU General Public License for more details.                            */
/*                                                                            */
/*    You should have received a copy of the GNU General Public License       */
/*    along with DC Solver.  If not, see <http://www.gnu.org/licenses/>.      */
/*                                                                            */
/******************************************************************************/

/*********************************  pantalla.h ********************************/
/*                                                                            */
/*   Origin:  Modulo diseñado, testado e implementado por                     */
/*                        Camilo Ramírez                                      */
/*                        Edward Duarte                                       */
/*                        David Orozco                                        */
/*                        Nicolas Pedraza                                     */
/*                                                                            */
/*   Notes:   None                                                            */
/*                                                                            */
/*   Register of Revisions (Debugging Process):                               */
/*                                                                            */
/*   DATE       RESPONSIBLE  COMMENT                                          */
/*   -----------------------------------------------------------------------  */
/*   May 16/21  C.Ramirez                                                     */
/*              E.Duarte                                                      */
/*              D.Orozco                                                      */
/*              N.Pedraza   Initial implementation                            */
/*                                                                            */
/******************************************************************************/

#ifndef _pantalla_H
#define _pantalla_H

/**************************** Symbolic  Constants *****************************/

/* --------------------- Predefined Sizes of Matrices ----------------------- */

/************************** Prototypes of Functions ***************************/

/* ---------------------------- Public Functions ---------------------------- */


/*FN***************************************************************************/
/*                                                                            */
/*   void pantalla(int* casos)                                                */
/*                                                                            */
/*    Propuse:         Tiene la función encargada de darle las instrucciones  */
/*                     o el ciclo de instrucciones a la pantalla para         */
/*                     que muestre los numeros de los latidos por minuto      */
/*                                                                            */
/*   Return:  Null                                                            */
/*                                                                            */
/*   Register of Revisions (June 6 2021):                                     */
/*                                                                            */
/*   DATE       RESPONSIBLE  COMMENT                                          */
/*   -----------------------------------------------------------------------  */
/*   JUNE 06/21 C.Ramirez                                                     */
/*              E.Duarte                                                      */
/*              D.Orozco                                                      */
/*              N.Pedraza                                                     */
/*              J.Girarldo                                                    */
/*                                                                            */
/******************************************************************************/

/*
  Posicion[7]: Vector que inicializa los puertos de entrada de cada una de las variables necesarias para cada segemento de la pantalla
  Tes:         Vector que inicializa las entradas de cada uno de los digitos de la pantalla
*/
byte posicion [7] = {2, 8, 5, 7, 6,  4,  3}, tes [4] = {13, 12, 11, 10};
/*
  fin:          Variable que se asegura que se recorra y se enciendan los 7 segmentos de un digito,
  aument:       Recorre la posición del digito a encender, ,
  i:            Variabnle para recorrer la totalidad de los digitos de la pantalla,
  posicionBit:  Recorre el segmento que se debe encender en cada digito de la pantalla,
  dig[4]:       Vector que almacena en cada posicion el valor de las decenas,centenas,etc que se debe imprimir en pantalla,
  display7[10]: Vector que contiene los caracteres de los numeros (en 7 bits) a traves de hexadecimales. Los numeros van de 0 a 9
*/
int fin = 0, aument = 0, i = 0, posicionBit = 6, dig[4],
    display7[10] = {0x7E, 0x30, 0x6D, 0x79, 0x33, 0x5B, 0x5F, 0x70, 0x7F, 0x7B};
// Variables para el funcionamiento basico del delay con el fin de mantener una vista de la pantalla
int casos1 = 1;
unsigned long tiempoDelay=1;
//Función encargada del refresco de la pantalla de leds
void pantalla(int* casos) {
  if (fin < 7) {
    // If que limita a que se recorran los 4 digitos de la pantalla
    if (i < 4) {
      // Selecciona los segmentos de de acuerdo al vector display7, que almacena hexadecimales
      digitalWrite(tes[i], bitRead(display7[dig[i]], posicionBit));
      (i)++; *casos = 3;
    }
    else {
                  // Enciende los segmentos seleccionados previamente
            digitalWrite(posicion[aument], HIGH);
            // Tiempo de espera meramente estetico, con el se permite una tonalidad en la pantalla mucho mas nitida
            delayA(tiempoDelay);
      // Apagado de los segmentos seleccionados
      digitalWrite(posicion[aument], LOW);
      // Re-definición de las variables para una repetibilidad en el proceso
      i = 0; *casos = 3; (posicionBit)--; aument++; fin++;
    }
  }
  // Re-definición de las variables para una repetibilidad en el proceso
  else {
    *casos = 1; posicionBit = 6; aument = 0; fin = 0;
  }
}
#endif  // _pantalla_H
