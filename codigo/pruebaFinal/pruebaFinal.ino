/* Ruler 1         2         3         4         5         6         7        */

/******************************************************************************/
/*	            _     _                  _                                    */
/*      	     | |   (_)                | |                                   */									
/*	  _ __  _   _| |___ _ _ __ ___   ___| |_ _ __ ___                         */
/*	 | '_ \| | | | / __| | '_ ` _ \ / _ \ __| '__/ _ \                        */
/*	 | |_) | |_| | \__ \ | | | | | |  __/ |_| | | (_) |                       */
/*   	 | .__/ \__,_|_|___/_|_| |_| |_|\___|\__|_|\___/                        */
/*	 | |                                                                      */
/*	 |_|                                                                      */
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


/* ------------------------ Inclusion of Own Headers ------------------------ */

/******************************************************************************/
/*                                                                            */
/*   Proposito de inclusión de nuestras propias librerias:                    */
/*                                                                            */
/*   Librerias creadas para la simplificación del codigo:                     */
/*                                                                            */
/*    1. BPM.h:        Tiene la función encargada de retornar los             */
/*                     latidos por minuto                                     */
/*    2. digitos.h:    Tiene la función encargada de separar los              */
/*                     digitos de los BPM                                     */
/*    3. lecturaBPM.h: Tiene la función encargada de realizar la              */
/*                     logica del caso 1 para evitar el efecto rebote         */
/*    4. pantalla.h:   Tiene la función encargada de darle las instrucciones  */
/*                     o el ciclo de instrucciones a la pantalla para         */
/*                     que muestre los numeros de los latidos por minuto      */
/*    5. delayA.h:     Tiene la función encargada de esperar los segundos     */
/*                     indicados para dar el resultado                        */
/*                                                                            */
/******************************************************************************/

#include "BPM.h"
#include "digitos.h"
#include "lecturaBPM.h"
#include "delayA.h"
#include "pantalla.h"

/************************** Prototypes of Functions ***************************/


/* ---------------------------- Public Functions ---------------------------- */


/************************* Main Function (SET UP,LOOP)*************************/

/*FN***************************************************************************/
/*                                                                            */
/*   Purpose: Simulate el pulso cardiaco de 4 personas al tiempo              */
/*                                                                            */
/*   Plan:                                                                    */
/*           Part 1: preparar 4 personas que quieran medirse el pulso         */
/*           Part 2: pedirle a las personas que opriman el pulsador cuando    */
/*                   haya un latido del corazón con ayuda de un fomendo       */
/*           Part 3: Imprimir en el primer segmento el número de la persona   */
/*                   para identificarla                                       */
/*           Part 4: Imprimir el pulso cardiaco de la persona                 */
/*           Part 5: Cambiar de persona con el pulsimetro restate y conocer   */
/*                   los pulsos restantes                                     */
/*           Part 6: Prender el led conforme a toquen los pulsadores para     */
/*                   que funcione como actuador al pulso                      */
/*                                                                            */
/*   Register of Revisions:                                                   */
/*                                                                            */
/*   DATE       RESPONSIBLE  COMMENT                                          */
/*   -----------------------------------------------------------------------  */
/*   JUNE 06/21 C.Ramirez                                                     */
/*              E.Duarte                                                      */
/*              D.Orozco                                                      */
/*              N.Pedraza                                                     */
/*              J.Girarldo   Initial implementation                           */
/*                                                                            */
/******************************************************************************/

//casos: Variable que recorre la totalidad de cases de la FSM
int  casos = 1;
// Función inicializadora
void setup() {
  //For que decalara las salidas de los segmentos de la pantalla
  for (int q = 0; q < 7; q++) {
    pinMode(posicion[q], OUTPUT);
  }
  //For que declara las salidas de los digitos de la pantalla
  //For que declara las entradas de los botones
  for (int q = 0; q < 4; q++) {
    pinMode(tes[q], OUTPUT);
    pinMode(botones[q], INPUT);
  }
  // Declaración de salida del led que simula las pulsaciones
  pinMode(led, OUTPUT);
  // Declaración del botón que cambia los pulsos en pantalla
  pinMode(botonP, INPUT);
  // Inicilizador de los baudios.
  Serial.begin(9600);
}
// Función que realiza el loop iterativo
void loop() {
  // Switch de la FSM
  switch (casos) {
    // Caso de lectura de la función bpm()
    case 1:
      base=lecturaBPM();
      casos = 2;
      break;
    // Caso para la separación de la variable base en el vector dig[]
    case 2:
      dividirDig(dig, base);
      i = 0;
      casos = 3;
      break;
    // Caso para la impresión de los latidos por minuto en pantalla
    case 3:
      // If que limita a que se recorran los 7 segmentos de cada uno de los digitos
      pantalla(&casos);
      break;
  }
}
