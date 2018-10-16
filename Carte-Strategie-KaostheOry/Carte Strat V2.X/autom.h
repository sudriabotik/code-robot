/* 
 * File:   autom.h
 * Author: Quentin
 *
 * Created on 1 février 2015, 17:12
 */

#ifndef AUTOM_H
#define	AUTOM_H

#ifdef	__cplusplus
extern "C" {
#endif


/******************************************************************************/
/******************************** INCLUDES ************************************/
/******************************************************************************/

#include "Config_robots.h"

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/



/******************************************************************************/
/****************************** DEFINES GLOBALES ******************************/
/******************************************************************************/


    /**************************************************************************/
    /*************************** DEFINE Général *******************************/
    /**************************************************************************/

    /**
     * Couleurs des zondes de départ
     */
    typedef enum
    {
        VERT,
        ORANGE
    }_enum_couleurs;
    

    /**************************************************************************/
    /*************************** DEFINE ID AX12 *******************************/
    /**************************************************************************/

#ifdef PETIT_ROBOT
    
    #define LOQUET 10 
    #define INTERRUPTEUR 1
    #define BAC 8
    
#endif

#ifdef  GROS_ROBOT
    
    #define BRAS_DROIT              5
    #define BRAS_GAUCHE             2
    #define PORTE_CANON             3
    #define LOQUET                  4

#endif

    /**************************************************************************/
    /*************************** POSITIONS AX12 *******************************/
    /**************************************************************************/

#ifdef  PETIT_ROBOT
    #define LOQUET_I 500
    #define LOQUET_D 725
    #define LOQUET_G 290

    #define INTERRUPTEUR_O 609
    #define INTERRUPTEUR_F 895
    
    #define BAC_I 700
    #define BAC_INT 550
    #define BAC_D 500
#endif

#ifdef GROS_ROBOT
    
    #define BRAS_DROIT_F  205
    #define BRAS_DROIT_O  812
    
    #define BRAS_GAUCHE_F  812
    #define BRAS_GAUCHE_O  222

    #define LOQUET_I  335
    #define LOQUET_O  490 //419//490//540 //525//490 //486 vert //484
    #define LOQUET_F 750

    #define PORTE_CANON_O 650
    #define PORTE_CANON_F 1200

#endif

    /**************************************************************************/
    /************************* DEFINE FLAG_ACTION *****************************/
    /**************************************************************************/

    typedef enum
    {
        NE_RIEN_FAIRE,                                       

#ifdef  PETIT_ROBOT
        // FLAG_ACTION DU PETIT ROBOT
#endif

#ifdef GROS_ROBOT
       // FLAG ACTION DU GROS ROBOT       
#endif 
     
        FIN_DE_MATCH
            
    }_enum_flag_action;




/******************************************************************************/
/******************************************************************************/
/******************************************************************************/


    
/******************************************************************************/
/****************************** Prototypes ************************************/
/******************************************************************************/

    void jack();
    void allumer_pompes ();
    void eteindre_pompe();
    void autom_20ms (void);
    void son_evitement (uint8_t melodie);

#ifdef  PETIT_ROBOT

#endif

#ifdef  GROS_ROBOT

    void rotation_us(void);

    // Fonctions d'init
    void init_jack();
    void init_depart();

    void rotation_us_avant();;
    
    //Fonction AX12

    uint8_t check_capteur (uint8_t cote);

    /**
     * Fonction qui permet d'inverser le côté en fonction de la couleur
     * @param cote : le cote (DROITE ou GAUCHE)
     * @return le côté opposé GAUCHE ou DROITE
     */
    uint8_t inversion_autom (uint8_t cote);

   
    /**************************************************************************/
    /**************************************************************************/
    /**************************************************************************/
#endif


/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

#ifdef	__cplusplus
}
#endif

#endif	/* AUTOM_H */

