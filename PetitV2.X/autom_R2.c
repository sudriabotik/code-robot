/******************************************************************************/
/************** Carte principale Robot 1 : DSPIC33FJ128MC804*******************/
/******************************************************************************/
/* Fichier 	: autom.c
 * Auteur  	: Quentin
 * Revision	: 1.0
 * Date		: 01 f�vrier 2015, 17:11
 *******************************************************************************
 *
 *
 ******************************************************************************/

/******************************************************************************/
/******************************** INCLUDES ************************************/
/******************************************************************************/

#include "system.h"

/******************************************************************************/
/***************************** FONCTIONS DIVERSES *****************************/
/******************************************************************************/

#ifdef PETIT_ROBOT

void jack()
{
    while(!SYS_JACK);
    while(SYS_JACK);
}

void allumer_pompes ()
{
    envoit_pwm(MOTEUR_X, 100);
}

void eteindre_pompe ()
{
    envoit_pwm(MOTEUR_X, 0);
}

void son_evitement (uint8_t melodie)
{/*
    commande_AX12(100, _4PARAM, WRITE_DATA, 0x29, 10);
    commande_AX12(100, _4PARAM, WRITE_DATA, 0x28, melodie);

  */}

/******************************************************************************/
/********************************  FONCTION AX12  *****************************/
/******************************************************************************/


/******************************************************************************/
/******************************** FONCTION BOUCLE *****************************/
/******************************************************************************/


void autom_20ms (void)
{

    //fonction qui definit les actions
    switch (FLAG_ACTION)
    {
        case NE_RIEN_FAIRE:
            break;
        case REJOINDRE_FUSEE:
            if (get_X() < 700){
                EVITEMENT_ADV.actif = OFF;
            }
            else{
                EVITEMENT_ADV.actif = ON;
            }
            break;
        default :
            break;
    }
    evitement();
    
    if (EVITEMENT_ADV.actif == true && EVITEMENT_ADV.detection == OFF)
    {
//        if (EVITEMENT_ADV.sens == MARCHE_AVANT)
//            rotation_us_avant();
//        else
//            rotation_us();
    }
    //else
        //position standart
    
}

#endif