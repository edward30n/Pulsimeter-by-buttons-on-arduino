/* Ruler 1         2         3         4         5         6         7        */

/******************************************************************************/
/*              _     _                  _                                    */
/*             | |   (_)                | |                                   */                  
/*    _ __  _  |_| |___ _ _ __ ___   ___| |_ _ __ ___                         */
/*   | '_ \| | | | / __| | '_ ` _ \ / _ \ __| '__/ _ \                        */
/*   | |_) | |_| | \__ \ | | | | | |  __/ |_| | | (_) |                       */
/*     | .__/ \__,_|_|___/_|_| |_| |_|\___|\__|_|\___/                        */
/*   | |                                                                      */
/*   |_|                                                                      */
/*	                _       _                                             */
/*	               | |     (_)                                            */
/*	   __ _ _ __ __| |_   _ _ _ __   ___      _   _ _ __   ___            */
/*	  / _` | '__/ _` | | | | | '_ \ / _ \    | | | | '_ \ / _ \           */
/*	 | (_| | | | (_| | |_| | | | | | (_) |   | |_| | | | | (_) |          */
/*	  \__,_|_|  \__,_|\__,_|_|_| |_|\___/     \__,_|_| |_|\___/           */
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

/*********************************  BPM.h *************************************/
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

#ifndef _BPM_H
#define _BPM_H

/**************************** Symbolic  Constants *****************************/

/* --------------------- Predefined Sizes of Matrices ----------------------- */

/************************** Prototypes of Functions ***************************/

/* ---------------------------- Public Functions ---------------------------- */


/*FN***************************************************************************/
/*                                                                            */
/*   void bpm(int lectura,int puerto,long unsigned int* primeraPulsacionT,    */
/*            long unsigned int* segundaPulsacionT,                           */
/*            long unsigned int* intervaloPulsaciones, int* BPM)              */
/*                                                                            */
/*   Propuse:      Tiene la función encargada de retornar los                 */
/*                 latidos por minuto                                         */
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
  led: led que se enciende cada vez que ocurre una pulsación.
*/
int led = 9;
// Variable booleana que define si el la puslación es la primera o no.
bool primeraPulsacion = false;
/* 
  Función que retorna un entero con el valor de las puslaciones por minuto, le ingresan
  por parametro variables y apuntadores para su correcto desarrollo
*/
int bpm(int lectura,int puerto,long unsigned int* primeraPulsacionT,long unsigned int* segundaPulsacionT,
long unsigned int* intervaloPulsaciones, int* BPM) {
  // Se activa el if una vez se pulse el botón
  if (lectura > 500 ) {
    // If para asegurtarse que sea la primera puslación
    if (primeraPulsacion == false) {
      // Asignación del tiempo de la primera pulsación
      *primeraPulsacionT = millis();
      // Ya se cuemple la primera pulsación, se asigna como true
      primeraPulsacion = true;
    }
    // Procedimiento para la segunda pulsación del botón
    else {
      // Asignación del tiempo de la segunda pulsación
      *segundaPulsacionT = millis();
      // Resta en los tiempos de pulsación
      *intervaloPulsaciones = *segundaPulsacionT - *primeraPulsacionT;
      // Redefinición de la primera puslación para obtener repetibilidad
      *primeraPulsacionT = *segundaPulsacionT;
      // Se enciende el led que simula las pulsaciones
      digitalWrite(led, HIGH);
  }
    // Se apaga el led que simula las pulsaciones
    digitalWrite(led, LOW);
    // Calculo de los latidos por minuto
      *BPM = (1.0 / *intervaloPulsaciones) * 60.0 * 1000;
    // Evita posibles errores de datos
    if (*BPM >= 0) {
      return *BPM;
    }
  }
}
#endif  // _BPM_H
