/******************************************************************************/
/************** Carte principale Robot 1 : DSPIC33FJ128MC804*******************/
/******************************************************************************/
/* Fichier 	: srategie.c
 * Auteur  	: Quentin
 * Revision	: 1.0
 * Date		: 07 février 2015, 22:47
 *******************************************************************************
 *
 *
 ******************************************************************************/

/******************************************************************************/
/******************************** INCLUDES ************************************/
/******************************************************************************/

#include "system.h"

//#define FIN_FACILE
#define FIN_DIFFICILE

int offset_front = 150;//270;
int offset_side = 165;
int vitesse_calage = 30;
int vitesse_std = 50;
int vitesse_passe_part = 40;
_Bool mouvement_b3_arrete = false;

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

void strategie()
{
    COULEUR = couleur_depart();
    #ifdef GROS_ROBOT
    // axID - > role
    //  3       funny action
    //  4       ar gauche billes 
    //  5       ar droit billes 
    //  12      av gauche billes
    //  15      bielle droit
    //  22      av droit billes 
    //  23      rampe cube
    //  26      bielle gauche
    
    //while(SYS_JACK);
    
    // Démarage du match
    CPT_TEMPS_MATCH.actif = true;
    EVITEMENT_ADV.actif = OFF;
    EVITEMENT_ADV.mode = STOP;
    
    /**************************** INITIALISATION ******************************/
    
    // init_position_robot(890, 40, 90);
    mvt_cage_bille(AR, lever);
    mvt_cage_bille(AV, abaisser);
    avalement(ARRETER);
        
    /**************************** STRAT 1 *************************************/
    /* petit crat 1
    *  petit crat 2
    *  dépose base
    *  grand crat 0 1er passage
    *  expulsion filet base */

//        /* dégagement base */
//        avancer_reculer(100, vitesse_std);
//        rejoindre(1070, 590, MARCHE_AVANT, vitesse_std);
//
//        /* déplacement cratère 1 */
//        rejoindre(737+offset_front, 560, MARCHE_AVANT, vitesse_std);
//
//        /* aspiration cratère 1 & dégagement */
//        avalement(AVALER);
//        avancer_reculer(-100, vitesse_std);
//
//        /* déplacement cratère 2 */
//        rejoindre(650, 1350, MARCHE_AVANT, vitesse_std);
//        rejoindre(692, 1700, MARCHE_AVANT, vitesse_std);
//        orienter(18, 100);
//
//        /* aspiration cratère 2 */
//        avancer_reculer(150, vitesse_std);
//        avalement(AVALER);
//        avancer_reculer(-150, vitesse_std);
//
//        /* dépose base */
//        orienter(-100, vitesse_std);
//        passe_part(650, 1110, MARCHE_AVANT, vitesse_passe_part, DEBUT_TRAJECTOIRE);
//        passe_part(1150, 360, MARCHE_AVANT, vitesse_passe_part, FIN_TRAJECTOIRE);
//        rejoindre(950, 240, MARCHE_AVANT, vitesse_std);
//
//        /* expulsion & dégagement */
//        orienter(195, 100);
//        avalement(EXPULSER);
//        avancer_reculer(-80, vitesse_std);
//        orienter(90, 100);
//        //calageX
//
//        /* déplacement cratère 0 */
//        passe_part(900, 1000, MARCHE_AVANT, vitesse_passe_part, DEBUT_TRAJECTOIRE);
//        passe_part(350, 1150, MARCHE_AVANT, vitesse_passe_part, FIN_TRAJECTOIRE);
//        rejoindre(275, 1350, MARCHE_AVANT, vitesse_std);
//
//        /* aspiration 1 cratère 0 & dégagement */
//        orienter(105, 100);
//        avancer_reculer(50, vitesse_std/2);
//        avalement(AVALER);
//        avancer_reculer(-100, vitesse_std);
//        orienter(-60, 100);
//
//        /* déplacement base */
//        passe_part(450, 1110, MARCHE_AVANT, vitesse_passe_part, DEBUT_TRAJECTOIRE);
//        passe_part(350, 700, MARCHE_AVANT, vitesse_passe_part, FIN_TRAJECTOIRE);
//        rejoindre(350, 500, MARCHE_ARRIERE, vitesse_std);
//
//        /* expulsion & dégagement */
//        orienter(195, 100);
//        avalement(EXPULSER);

    /**************************** STRAT 2 *************************************/
    /* petit crat 1
    *  grand crat 0 1er passage
    *  grand crat 0 2em passage
    *  dépose base
    *  petit crat 2
    *  dépose base */
            
//        /* dégagement base */
//        avancer_reculer(100, vitesse_std);
//        rejoindre(1070, 590, MARCHE_AVANT, vitesse_std);
//        
//        /* déplacement cratère 1 */
//        rejoindre(737+offset_front, 560, MARCHE_AVANT, vitesse_std);
//        
//        /* aspiration cratère 1 & dégagement */
//        avalement(AVALER);
//        avancer_reculer(-100, vitesse_std);
//        orienter(90, 100);
//        
//        /* déplacement cratère 0 */
//        passe_part(900, 1000, MARCHE_AVANT, vitesse_passe_part, DEBUT_TRAJECTOIRE);
//        passe_part(350, 1150, MARCHE_AVANT, vitesse_passe_part, FIN_TRAJECTOIRE);
//        rejoindre(275, 1350, MARCHE_AVANT, vitesse_std);
//        
//        /* aspiration 1 cratère 0 & dégagement */
//        orienter(105, 100);
//        avancer_reculer(50, vitesse_std/2);
//        avalement(AVALER);
//        avancer_reculer(-100, vitesse_std);
//        orienter(40, 100);
//        
//        /* déplacement 2 cratère 0 */
//        passe_part(600, 1580, MARCHE_AVANT, vitesse_passe_part, DEBUT_TRAJECTOIRE);
//        passe_part(692, 1700, MARCHE_AVANT, vitesse_passe_part, FIN_TRAJECTOIRE);
//        
//        /* aspiration 2 cratère 0 & dégagement */
//        orienter(165, 100);
//        avancer_reculer(60, vitesse_std);
//        avalement(AVALER);
//        avancer_reculer(-100, vitesse_std);
//        orienter(-120, 100);
//        
//        /* dépose base */
//        passe_part(650, 1110, MARCHE_AVANT, vitesse_passe_part, DEBUT_TRAJECTOIRE);
//        passe_part(1150, 360, MARCHE_AVANT, vitesse_passe_part, FIN_TRAJECTOIRE);
//        rejoindre(950, 240, MARCHE_AVANT, vitesse_std);
//        
//        /* expulsion & dégagement */
//        orienter(195, 100);
//        avalement(EXPULSER);
//        avancer_reculer(-100, vitesse_std);
//        orienter(90, 100);
//        
//        /* déplacement cratère 1 */
//        rejoindre(650, 1350, MARCHE_AVANT, vitesse_std);
//        rejoindre(692, 1700, MARCHE_AVANT, vitesse_std);
//        orienter(18, 100);
//        
//        /* aspiration cratère 2 */
//        avancer_reculer(150, vitesse_std);
//        avalement(AVALER);
//        avancer_reculer(-150, vitesse_std);
//        
//        /* dépose base */
//        orienter(-100, vitesse_std);
//        passe_part(650, 1110, MARCHE_AVANT, vitesse_passe_part, DEBUT_TRAJECTOIRE);
//        passe_part(1150, 360, MARCHE_AVANT, vitesse_passe_part, FIN_TRAJECTOIRE);
//        rejoindre(950, 240, MARCHE_AVANT, vitesse_std);
//        
//        /* expulsion & dégagement */
//        orienter(195, 100);
//        avalement(EXPULSER);
//        avancer_reculer(-80, vitesse_std);
//        orienter(90, 100);
    
           
    #endif

        
    #ifdef PETIT_ROBOT
    // axID - > role
    //  1       bras gauche
    //  2       rotation pince gauche
    //  3       bras droit
    //  4       rotation pince droit
    angle_AX12(2, 25, 150, SANS_ATTENTE);   // gauche prep capture module
    angle_AX12(4, 973, 150, SANS_ATTENTE);  // droit prep capture module
    //sorties des bras
    angle_AX12(1, 633, 200, SANS_ATTENTE);
    angle_AX12(3, 997, 150, SANS_ATTENTE);
    delay_ms(2000);
    // calages
    angle_AX12(2, 25, 150, SANS_ATTENTE);   // gauche prep capture module
    angle_AX12(4, 973, 150, SANS_ATTENTE);  // droit prep capture module
    //rentrer les bras
    angle_AX12(1, 940, 200, SANS_ATTENTE);
    angle_AX12(3, 695, 150, SANS_ATTENTE);
    
    while(!SYS_JACK);
    CPT_TEMPS_MATCH.actif = true;

    /**************************** INITIALISATION ******************************/
    // COULEUR 0 = JAUNE; 
    init_position_robot(42, 930, 0);
    // calages
    angle_AX12(2, 25, 150, SANS_ATTENTE);   // gauche prep capture module
    angle_AX12(4, 973, 150, SANS_ATTENTE);  // droit prep capture module
    //sorties des bras
    angle_AX12(1, 633, 200, SANS_ATTENTE);
    angle_AX12(3, 997, 150, SANS_ATTENTE);
     
         
    /**************************** STRAT 1 *************************************/
    /* tri 1
     * tri 2
     * dépose B1
     * mono1
     * mono2
     * déposeB2
     * tri3
     * déposeB1
     * monofusée1
     * monofusée2
     * déposeB2
     */

    delay_ms(750);
    calage_X(42, 0, MARCHE_ARRIERE, vitesse_calage);
    
    EVITEMENT_ADV.actif = ON;
    
    if (COULEUR == BLEU) {
        /* déplacement & ventouse tri1 */
        pompes(POMPE_GAUCHE, ON);
        rejoindre(600, 930, MARCHE_AVANT, vitesse_std); // position tri1 : 600 - 1000
        angle_AX12(2, 335, 80, SANS_ATTENTE);   // gauche prep depose module
        
        /* déplacement & ventouse tri2 */
        pompes(POMPE_DROITE, ON);
        //rejoindre(1150, 570, MARCHE_AVANT, vitesse_std);
        rejoindre(1100, 570, MARCHE_AVANT, vitesse_std); //Comme jaune
        angle_AX12(4, 660, 80, SANS_ATTENTE); // droite prep depose module
        
        /* déposer en B1 */
        //rejoindre(865, 320, MARCHE_AVANT, vitesse_std);
        rejoindre(840, 320, MARCHE_AVANT, vitesse_std); //Comme jaune
        EVITEMENT_ADV.actif = OFF;
        orienter(-90, 100);
        avancer_reculer(80, vitesse_std);
        calage_Y(218, -90, MARCHE_AVANT, vitesse_calage);
        pompes(POMPE_GAUCHE, OFF);
        delay_ms(500);
        pompes(POMPE_DROITE, OFF);
        EVITEMENT_ADV.actif = ON;

        
        /* dégagement */
        avancer_reculer(-120, vitesse_std);
        angle_AX12(2, 25, 150, SANS_ATTENTE);   // gauche prep capture module
        angle_AX12(4, 973, 150, SANS_ATTENTE);  // droit prep capture module
        
        /* déplacement & ventouse Mono1 */
        pompes(POMPE_GAUCHE, ON);
        EVITEMENT_ADV.actif = OFF;
        rejoindre(620, 280, MARCHE_AVANT, vitesse_std); // position Mono1 : 600 - 200
        angle_AX12(2, 335, 80, SANS_ATTENTE);  //gauche prep depose module
        
        /* déplacement & ventouse Mono2 */
        
        pompes(POMPE_DROITE, ON);
        cibler(1745, 800, vitesse_std);
        EVITEMENT_ADV.actif = ON;
        //rejoindre(1770, 845, MARCHE_AVANT, vitesse_std);
        rejoindre(1745, 800, MARCHE_AVANT, vitesse_std); //Comme jaune
        angle_AX12(4, 660, 80, SANS_ATTENTE); // droite prep depose module
        
        /* dégagement */
        avancer_reculer(-150, vitesse_std);
        EVITEMENT_ADV.actif = OFF;
        orienter(-120, 100);

        /* déplacement B3 */
        
        passe_part(1400, 500, MARCHE_AVANT, vitesse_passe_part, DEBUT_TRAJECTOIRE);
        EVITEMENT_ADV.phase = DEPOSE_B3;
        EVITEMENT_ADV.actif = ON;
        //if (FLAG_ACTION != INTERRUPTION_DEPOSE_B3)
        passe_part(1200, 800, MARCHE_AVANT, vitesse_passe_part, MILIEU_TRAJECTOIRE);
        //else
        //    avancer_reculer(-100, vitesse_std);
        //if (FLAG_ACTION != INTERRUPTION_DEPOSE_B3)
        passe_part(1100, 1100, MARCHE_AVANT, vitesse_passe_part, MILIEU_TRAJECTOIRE);
        //else
        //    avancer_reculer(-100, vitesse_std);
        //if (FLAG_ACTION != INTERRUPTION_DEPOSE_B3)
        passe_part(1400 ,1250, MARCHE_AVANT, vitesse_passe_part, FIN_TRAJECTOIRE);
        //else
        //    avancer_reculer(-100, vitesse_std);
        EVITEMENT_ADV.actif = OFF;
        EVITEMENT_ADV.phase = DEFAUT;
        orienter(90, vitesse_std);

        /* déposer en B3 */
        calage_Y(1430, 90, MARCHE_AVANT, vitesse_calage);
        pompes(POMPE_GAUCHE, OFF);
        delay_ms(500);
        pompes(POMPE_DROITE, OFF);
        
        /* dégagement */
        avancer_reculer(-100, vitesse_std);
        orienter(0, 100);
        avancer_reculer(-100, vitesse_std);
        orienter(180, 100);
        angle_AX12(2, 25, 150, SANS_ATTENTE);   // gauche prep capture module
        angle_AX12(4, 973, 150, SANS_ATTENTE);  // droit prep capture module

        /* déplacement & ventouse mono fusée 1 */
        //rejoindre(300, 1200, MARCHE_AVANT, vitesse_std);
        EVITEMENT_ADV.actif = ON;
        FLAG_ACTION = REJOINDRE_FUSEE;
        rejoindre(280, 1180, MARCHE_AVANT, vitesse_std); //Comme jaune
        EVITEMENT_ADV.actif = OFF;
        orienter(180, 100);
        pompes(POMPE_DROITE, ON);
        avancer_reculer(75, vitesse_std);
        avancer_reculer(-110, vitesse_std);
        angle_AX12(4, 660, 80, SANS_ATTENTE); // droite prep depose module
        
        /* déplacement & ventouse mono fusée 2*/
        orienter(143, 100);
        pompes(POMPE_GAUCHE, ON);
        avancer_reculer(120, vitesse_std); // à régler
        avancer_reculer(-145, vitesse_std);
        angle_AX12(2, 335, 80, SANS_ATTENTE);  //gauche prep depose module
        
        /* dégagement */
        orienter(0, 100);
        FLAG_ACTION = NE_RIEN_FAIRE;
        EVITEMENT_ADV.actif = ON;

        /* déplacement B2 */
        //rejoindre(1420, 1250, MARCHE_AVANT, vitesse_std);
        rejoindre(1370, 1355, MARCHE_AVANT, vitesse_std); //Comme jaune
        EVITEMENT_ADV.actif = OFF;
        orienter(-45, 100);
        avancer_reculer(150, vitesse_std);

        /* dépose B2 */
        pompes(POMPE_GAUCHE, OFF);
        delay_ms(500);
        pompes(POMPE_DROITE, OFF);

        /* dégagement */
        avancer_reculer(-80, vitesse_std);
        angle_AX12(2, 25, 150, SANS_ATTENTE);   // gauche prep capture module
        angle_AX12(4, 973, 150, SANS_ATTENTE);  // droit prep capture module

        /* déplacement & mono fusée 3 */
        cibler(280, 1230, 100);
        FLAG_ACTION = REJOINDRE_FUSEE;
        EVITEMENT_ADV.actif = ON;
        rejoindre(280, 1230, MARCHE_AVANT, vitesse_std);
        EVITEMENT_ADV.actif = OFF;
        orienter(180, 100); 
        //rejoindre(300, 1230, MARCHE_AVANT, vitesse_std);
        pompes(POMPE_DROITE, ON);
        avancer_reculer(75, vitesse_std);
        avancer_reculer(-120, vitesse_std);
        //angle_AX12(4, 660, 80, SANS_ATTENTE); // droite prep depose module
        
        /* déplacement & ventouse mono fusée 4*/
        orienter(143, 100);
        pompes(POMPE_GAUCHE, ON);
        avancer_reculer(120, vitesse_std); // à régler
        avancer_reculer(-145, vitesse_std);
        //angle_AX12(2, 335, 80, SANS_ATTENTE);  //gauche prep depose module
        
        
#ifdef FIN_FACILE
        /*Dépose zone*/
        //rejoindre(250, 1000, MARCHE_AVANT, vitesse_std/2);
        orienter(-120, 100);
        avancer_reculer(150, vitesse_std);
        pompes(POMPE_DROITE, OFF);
        pompes(POMPE_GAUCHE, OFF);
        FLAG_ACTION = NE_RIEN_FAIRE;
#endif

#ifdef FIN_DIFFICILE
        /* dégagement */
        angle_AX12(4, 660, 80, SANS_ATTENTE); // droite prep depose module
        angle_AX12(2, 335, 80, SANS_ATTENTE);  //gauche prep depose module
        orienter(0, 100);        
        FLAG_ACTION = NE_RIEN_FAIRE;
        EVITEMENT_ADV.actif = ON;
        /* déplacement B1 */
        passe_part(900, 900, MARCHE_AVANT, vitesse_passe_part, DEBUT_TRAJECTOIRE);
        passe_part(1120, 500, MARCHE_AVANT, vitesse_passe_part, MILIEU_TRAJECTOIRE);
        EVITEMENT_ADV.actif = OFF;
        rejoindre(1120, 320, MARCHE_AVANT, vitesse_std);
        //rejoindre(1250, 400, MARCHE_AVANT, vitesse_std); //Comme jaune
        orienter(-90, 100); // remplacer par cibler();
        avancer_reculer(60, vitesse_std);
        
        calage_Y(218, -90, MARCHE_AVANT, vitesse_calage);

        /* dépose pince gauche */
        pompes(POMPE_DROITE, OFF);
        
        /* dégagement */
        EVITEMENT_ADV.actif = ON;
        avancer_reculer(-100, vitesse_std);
        EVITEMENT_ADV.actif = OFF;
        angle_AX12(4, 660, 80, SANS_ATTENTE); // droite prep depose module
        orienter(90, 100);
        
        
        EVITEMENT_ADV.actif = ON;
        
        /* déplacement B2 ou BASE 0*/
        passe_part(900, 1000, MARCHE_AVANT, vitesse_passe_part, DEBUT_TRAJECTOIRE);
        
        passe_part(250, 1000, MARCHE_AVANT, vitesse_passe_part, FIN_TRAJECTOIRE);
//        orienter(180, 100);
//        avancer_reculer(400, vitesse_std);
        angle_AX12(2, 25, 150, SANS_ATTENTE);
        delay_ms(500);
        pompes(POMPE_GAUCHE, OFF);
//        passe_part(1100, 1200, MARCHE_AVANT, vitesse_passe_part, FIN_TRAJECTOIRE);
//        //rejoindre(1400, 1400, MARCHE_AVANT, vitesse_std);
//        rejoindre(1500, 1340, MARCHE_AVANT, vitesse_std); //Comme jaune
//        EVITEMENT_ADV.actif = OFF;
//        orienter(-45, 100);
//        avancer_reculer(100, vitesse_std); 
//
//        /* dépose B2 */
//        pompes(POMPE_GAUCHE, OFF);
//        pompes(POMPE_DROITE, OFF);
#endif
        
    } else {
        /* déplacement & ventouse tri1 */
        pompes(POMPE_DROITE, ON);
        rejoindre(600, 930, MARCHE_AVANT, vitesse_std); // position tri1 : 600 - 1000
        angle_AX12(4, 660, 80, SANS_ATTENTE); // droite prep depose module
        
        /* déplacement & ventouse tri2 */
        pompes(POMPE_GAUCHE, ON);
        rejoindre(1150, 550, MARCHE_AVANT, vitesse_std);
        angle_AX12(2, 335, 80, SANS_ATTENTE);   // gauche prep depose module
        //EVITEMENT_ADV.actif = OFF;
        
        /* déposer en B1 */
        EVITEMENT_ADV.actif = OFF;
        rejoindre(865, 320, MARCHE_AVANT, vitesse_std);
        
        orienter(-90, 100);
        avancer_reculer(80, vitesse_std);    //à voir ??? 
        calage_Y(218, -90, MARCHE_AVANT, vitesse_calage);
        pompes(POMPE_DROITE, OFF);
        delay_ms(500);
        pompes(POMPE_GAUCHE, OFF);
        EVITEMENT_ADV.actif = ON;

        
        /* dégagement */
        avancer_reculer(-120, vitesse_std);
        angle_AX12(2, 25, 150, SANS_ATTENTE);   // gauche prep capture module
        angle_AX12(4, 973, 150, SANS_ATTENTE);  // droit prep capture module
        
        /* déplacement & ventouse Mono1 */
        pompes(POMPE_DROITE, ON);
        EVITEMENT_ADV.actif = OFF;
        rejoindre(650, 285, MARCHE_AVANT, vitesse_std); // position Mono1 : 600 - 200
        angle_AX12(4, 660, 80, SANS_ATTENTE); // droite prep depose module
        
        /* déplacement & ventouse Mono2 */
        pompes(POMPE_GAUCHE, ON);
        cibler(1745, 825, vitesse_std);
        EVITEMENT_ADV.actif = ON;
        rejoindre(1745, 825, MARCHE_AVANT, vitesse_std); // position mono2 : 1850 - 800
        angle_AX12(2, 335, 80, SANS_ATTENTE);  //gauche prep depose module
        
        
        /* dégagement */
        avancer_reculer(-150, vitesse_std);
        EVITEMENT_ADV.actif = OFF;
        orienter(-120, 100);

        /* déplacement B3 */
        passe_part(1400, 500, MARCHE_AVANT, vitesse_passe_part, DEBUT_TRAJECTOIRE);
        EVITEMENT_ADV.actif = ON;
        passe_part(1200, 800, MARCHE_AVANT, vitesse_passe_part, MILIEU_TRAJECTOIRE);
        passe_part(1100, 1100, MARCHE_AVANT, 95, MILIEU_TRAJECTOIRE);
        passe_part(1400 ,1250, MARCHE_AVANT, 95, FIN_TRAJECTOIRE);
        EVITEMENT_ADV.actif = OFF;
        orienter(90, vitesse_std);

        /* déposer en B3 */
        calage_Y(1430, 90, MARCHE_AVANT, vitesse_calage); 
        pompes(POMPE_GAUCHE, OFF);
        delay_ms(500);
        pompes(POMPE_DROITE, OFF);

        /* dégagement */
        avancer_reculer(-100, vitesse_std);
        
        orienter(0, 100);
        avancer_reculer(-100, vitesse_std);
        orienter(180, 100);
        
        angle_AX12(2, 25, 150, SANS_ATTENTE);   // gauche prep capture module
        angle_AX12(4, 973, 150, SANS_ATTENTE);  // droit prep capture module

        /* déplacement & ventouse mono fusée 1 */
        EVITEMENT_ADV.actif = ON;
        FLAG_ACTION = REJOINDRE_FUSEE;
        rejoindre(280, 1170, MARCHE_AVANT, vitesse_std);
        //desactiver evitement quand y < ~500
        EVITEMENT_ADV.actif = OFF;
        orienter(180, 100);
        pompes(POMPE_GAUCHE, ON);
        avancer_reculer(105, vitesse_std);  //105 //85 //95 //115
        avancer_reculer(-115, vitesse_std);
        angle_AX12(2, 335, 80, SANS_ATTENTE);  //gauche prep depose module
        
        
        /* déplacement & ventouse mono fusée 2*/
        //rejoindre(260, 1280, MARCHE_AVANT, vitesse_std);
        orienter(90, 100);
        avancer_reculer(140, vitesse_std); // à régler 900 ???
        orienter(180, 100);
        pompes(POMPE_DROITE, ON);
        avancer_reculer(115, vitesse_std); // à régler 900 ??? //110 //125
        avancer_reculer(-145, vitesse_std);
        angle_AX12(4, 660, 80, SANS_ATTENTE); // droite prep depose module
        
        /* dégagement */
        orienter(0, 100);
        FLAG_ACTION = NE_RIEN_FAIRE;
        EVITEMENT_ADV.actif = ON;

        /* déplacement B2 */
        rejoindre(1370, 1355, MARCHE_AVANT, vitesse_std);
        EVITEMENT_ADV.actif = OFF;
        orienter(-45, 100);
        avancer_reculer(60, vitesse_std); //ancienne distance 100 //50

        /* dépose B2 */
        pompes(POMPE_GAUCHE, OFF);
        delay_ms(500);
        pompes(POMPE_DROITE, OFF);

        /* dégagement */
        //calage_Y(1430, 90, MARCHE_ARRIERE, vitesse_calage);
        avancer_reculer(-80, vitesse_std);
        angle_AX12(2, 25, 150, SANS_ATTENTE);   // gauche prep capture module
        angle_AX12(4, 973, 150, SANS_ATTENTE);  // droit prep capture module

        /* déplacement & mono fusée 3 */
        cibler(280, 1170, 100);
        FLAG_ACTION = REJOINDRE_FUSEE;
        EVITEMENT_ADV.actif = ON;
        rejoindre(280, 1170, MARCHE_AVANT, vitesse_std);
        EVITEMENT_ADV.actif = OFF; //si y sup à 500
        //orienter(180, 100);
        pompes(POMPE_GAUCHE, ON);
        avancer_reculer(95, vitesse_std);
        avancer_reculer(-110, vitesse_std);
#ifdef FIN_DIFFICILE
        angle_AX12(2, 335, 80, SANS_ATTENTE);  //gauche prep depose module
#endif
        
        /* déplacement & ventouse mono fusée 4*/
        //rejoindre(260, 1280, MARCHE_AVANT, vitesse_std);
        orienter(100, 100);
        avancer_reculer(140, vitesse_std); // à régler 900 ???
        orienter(190, 100);
        pompes(POMPE_DROITE, ON);
        avancer_reculer(120, vitesse_std); // à régler
        avancer_reculer(-145, vitesse_std);
#ifdef FIN_DIFFICILE
        angle_AX12(4, 660, 80, SANS_ATTENTE); // droite prep depose module
#endif

#ifdef FIN_FACILE
         /*Dépose zone*/
        rejoindre(250, 1000, MARCHE_AVANT, vitesse_std/2);
        pompes(POMPE_DROITE, OFF);
        pompes(POMPE_GAUCHE, OFF);
#endif
        
#ifdef FIN_DIFFICILE
        /* dégagement */
        orienter(0, 100);
        FLAG_ACTION = NE_RIEN_FAIRE;
        EVITEMENT_ADV.actif = ON;
        
        //Simplification de la strat deux derniers cylindres
        /* déplacement B1 */
        passe_part(900, 900, MARCHE_AVANT, vitesse_passe_part, DEBUT_TRAJECTOIRE);
        passe_part(1120, 500, MARCHE_AVANT, vitesse_passe_part, MILIEU_TRAJECTOIRE);
        EVITEMENT_ADV.actif = OFF;
        rejoindre(1250, 400, MARCHE_AVANT, vitesse_std); //1220, 380
        orienter(-90, 100); // remplacer par cibler();
        avancer_reculer(60, vitesse_std);
        angle_AX12(4, 660, 80, SANS_ATTENTE); // droite prep depose module
        angle_AX12(2, 335, 80, SANS_ATTENTE);  //gauche prep depose module
        calage_Y(218, -90, MARCHE_AVANT, vitesse_calage);

        /* dépose pince droite lul */
        pompes(POMPE_GAUCHE, OFF);
        
        /* dégagement */
        avancer_reculer(-100, vitesse_std);
        angle_AX12(2, 335, 80, SANS_ATTENTE);  //gauche prep depose module
        orienter(90, 100);
        EVITEMENT_ADV.actif = ON;
        
        /* déplacement B2 */
        passe_part(900, 650, MARCHE_AVANT, vitesse_passe_part, DEBUT_TRAJECTOIRE);
        passe_part(1100, 1200, MARCHE_AVANT, vitesse_passe_part, FIN_TRAJECTOIRE); //1100 1200
        rejoindre(1500, 1340, MARCHE_AVANT, vitesse_std);
        EVITEMENT_ADV.actif = OFF;
        orienter(-45, 100);
        avancer_reculer(100, vitesse_std);

        /* dépose B2 */
        pompes(POMPE_DROITE, OFF);
        pompes(POMPE_GAUCHE, OFF);
#endif
    }
    #endif
}


void homologation()
{
    COULEUR = couleur_depart();

#ifdef GROS_ROBOT

    // Inits avant démarage du robot :
    init_jack();

    while(!SYS_JACK);

    // Démarage du match
    CPT_TEMPS_MATCH.actif = true;
    EVITEMENT_ADV.actif = OFF;
    EVITEMENT_ADV.mode = STOP;

    init_position_robot(180., 988., 0.);
#endif

#ifdef PETIT_ROBOT

        init_position_robot (0, 0, 0);
        printf("\n\ryouhou");
        avancer_reculer(100, 100);

#endif

}

void reglage_odometrie()
{

    delay_ms(2000);
    //while(!SYS_JACK);
    COULEUR = couleur_depart();
#ifdef GROS_ROBOT
    init_jack();
#endif
    EVITEMENT_ADV.actif = OFF;
    
      init_position_robot (0., 0., 0.);
          //orienter(5, 100);




            init_position_robot (-100., 0., 0.);
            rejoindre(0, 0, MARCHE_AVANT, 100);
            trapeze(MARCHE_AVANT);
            trapeze(MARCHE_AVANT);
            trapeze(MARCHE_AVANT);
            trapeze(MARCHE_AVANT);
            trapeze(MARCHE_AVANT);

//           faire_des_tours(-32);
            while(1);
////
////            TIMER_DEBUG = ACTIVE;
//            init_position_robot(0, 0, 0);
            ////Horraire
//       rejoindre(2000, 0, MARCHE_AVANT, 50);
//       orienter(90, 50);
//        rejoindre(300, 0, MARCHE_AVANT, 50);
//        orienter(-90, 50);
//        rejoindre(2000, 0, MARCHE_AVANT, 50);
//        orienter(90, 50);
//        rejoindre(300, 0, MARCHE_AVANT, 50);
//        orienter (-90, 50);
//        rejoindre(2000, 0, MARCHE_AVANT, 50);
//        orienter(90, 50);
//        rejoindre(300, 0, MARCHE_AVANT, 50);
//        orienter (-90, 50);
//        rejoindre(2000, 0, MARCHE_AVANT, 50);
//        orienter(90, 50);
//        rejoindre(300, 0, MARCHE_AVANT, 50);
//        orienter (-90, 50);
//        rejoindre(2000, 0, MARCHE_AVANT, 50);
//        orienter(90, 50);
//        rejoindre(300, 0, MARCHE_AVANT, 50);
//        orienter (-90, 50);
//        rejoindre(2000, 0, MARCHE_AVANT, 50);
//        orienter(90, 50);
//        rejoindre(300, 0, MARCHE_AVANT, 50);
//        orienter(-90, 50);


            //// Anti horaire
        rejoindre(2000, 0, MARCHE_AVANT, 50);
        orienter(-90, 50);
        rejoindre(300, 0, MARCHE_AVANT, 50);
        orienter(90, 50);
        rejoindre(2000, 0, MARCHE_AVANT, 50);
        orienter(-90, 50);
        rejoindre(300, 0, MARCHE_AVANT, 50);
        orienter (90, 50);
        rejoindre(2000, 0, MARCHE_AVANT, 50);
        orienter(-90, 50);
        rejoindre(300, 0, MARCHE_AVANT, 50);
        orienter (90, 50);
        rejoindre(2000, 0, MARCHE_AVANT, 50);
        orienter(-90, 50);
        rejoindre(300, 0, MARCHE_AVANT, 50);
        orienter (90, 50);
        rejoindre(2000, 0, MARCHE_AVANT, 50);
        orienter(-90, 50);
        rejoindre(300, 0, MARCHE_AVANT, 50);
        orienter (90, 50);
        rejoindre(2000, 0, MARCHE_AVANT, 50);
        orienter(-90, 50);
        rejoindre(300, 0, MARCHE_AVANT, 50);
        orienter(90, 50);
        rejoindre(500, 0, MARCHE_AVANT, 100);


//        rejoindre(2000, 0, MARCHE_AVANT, 100);
//        rejoindre(300, 0, MARCHE_AVANT, 100);
//        rejoindre(2000, 0, MARCHE_AVANT, 100);
//        rejoindre(300, 0, MARCHE_AVANT, 100);
//        rejoindre(2000, 0, MARCHE_AVANT, 100);
//        rejoindre(300, 0, MARCHE_AVANT, 100);
//        rejoindre(2000, 0, MARCHE_AVANT, 100);
//        rejoindre(300, 0, MARCHE_AVANT, 100);
//        rejoindre(2000, 0, MARCHE_AVANT, 100);
//        rejoindre(300, 0, MARCHE_AVANT, 100);
//        rejoindre(2000, 0, MARCHE_AVANT, 100);
//        rejoindre(300, 0, MARCHE_AVANT, 100);
//        rejoindre(2000, 0, MARCHE_AVANT, 100);
//        rejoindre(300, 0, MARCHE_AVANT, 100);
//        rejoindre(500, 0, MARCHE_AVANT, 100);
//        TIMER_DEBUG = DESACTIVE;

        delay_ms(10000);
}

void pompes(uint8_t pompe, uint8_t onOff)
    {
        if (pompe == POMPE_DROITE)
        {
            if(onOff == ON)
                envoit_pwm(MOTEUR_X, PWM_X_VALEUR_MAX);
            else
                envoit_pwm(MOTEUR_X, 0.);
        }
        
        else if(pompe == POMPE_GAUCHE)
        {
            alimenter_moteur_Y(onOff, MARCHE_AVANT);
        }
    }
//
//void prendre_module(uint8_t zone, uint8_t nb_module, double pourcentage_vitesse)
//{
//    //rejoindre(zone.mod1.x, zone.mod1.y, MARCHE_AVANT, pourcentage_vitesse);
//    bras(BRAS_DROIT, SORTI);
//    //avancer_reculer(zone.avance, 30);
//    pompes(POMPE_DROITE, ON);
//    delay_ms(500);
//    //avancer_reculer(-(zone.avance), 30);
//    
//    
//}

void avalement(uint8_t position)
{
    switch(position)
    {
        // sort cube + actionne le moteur en ejection des balles + rentre cube
        case EXPULSER:
            angle_AX12(15, 715, 150, AVEC_ATTENTE);
            angle_AX12(26, (1024-715), 150, AVEC_ATTENTE);
            lancer_autom_AX12();
            delay_ms(750);
            envoit_pwm(MOTEUR_X, PWM_X_VALEUR_MAX/2);
            delay_ms(1500);
            angle_AX12(15, 250, 150, AVEC_ATTENTE);
            angle_AX12(26, (1024-250), 150, AVEC_ATTENTE);
            lancer_autom_AX12();
            delay_ms(750);
            break;
        // sort cube + actionne le moteur en avalement des balles + rentre cube
        case AVALER:
            angle_AX12(15, 715, 150, AVEC_ATTENTE);
            angle_AX12(26, (1024-715), 150, AVEC_ATTENTE);
            lancer_autom_AX12();
            delay_ms(750);
            SENS_MOTEUR_X = RECULER_MOTEUR_X;
            REGISTRE_MOTEUR_X = (uint16_t) PWM_X_VALEUR_MAX;
            delay_ms(750);
            angle_AX12(15, 250, 150, AVEC_ATTENTE);
            angle_AX12(26, (1024-250), 150, AVEC_ATTENTE);
            lancer_autom_AX12();
            delay_ms(750);
            break;
        // rentre cube + arrete moteur
        case ARRETER:
            angle_AX12(15, 300, 150, AVEC_ATTENTE);
            angle_AX12(26, (1024-300), 150, AVEC_ATTENTE);
            lancer_autom_AX12();
            envoit_pwm(MOTEUR_X, 0);
            break;
    }
}
//
//void mvt_cube(uint8_t action)
//{
//    switch(action)
//    {
//        case rentrer: 
//            angle_AX12(15, 90, 150, AVEC_ATTENTE);
//            angle_AX12(26, (1024-90), 150, AVEC_ATTENTE);
//            lancer_autom_AX12();
//            delay_ms(1500);
//            break;
//        case aspiration:
//            angle_AX12(15, 250, 150, AVEC_ATTENTE);
//            angle_AX12(26, (1024-250), 150, AVEC_ATTENTE);
//            lancer_autom_AX12();
//            delay_ms(1500);
//            break;
//        case sortir:
//            angle_AX12(15, 715, 150, AVEC_ATTENTE);
//            angle_AX12(26, (1024-715), 150, AVEC_ATTENTE);
//            lancer_autom_AX12();
//            delay_ms(1500);
//            break;
//    }
//}

void mvt_cage_bille(uint8_t type, uint8_t action)
{
    switch (type)
    {
        case AR:
            switch(action)
            {
                case lever:
                    angle_AX12(5, 200, 150, AVEC_ATTENTE);
                    angle_AX12(4, (1024-200), 150, AVEC_ATTENTE);
                    lancer_autom_AX12();
                    break;
                case abaisser:
                    angle_AX12(5, 512, 150, AVEC_ATTENTE);
                    angle_AX12(4, 512, 150, AVEC_ATTENTE);
                    lancer_autom_AX12();
                    break;
            }
            break;
        case AV:
            switch(action)
            {
                case lever:
                    angle_AX12(22, 200, 150, AVEC_ATTENTE);
                    angle_AX12(12, (1024-200), 150, AVEC_ATTENTE);
                    lancer_autom_AX12();
                    break;
                case abaisser:
                    angle_AX12(22, 512, 150, AVEC_ATTENTE);
                    angle_AX12(12, 400, 150, AVEC_ATTENTE); // valeur angle par défault : 512
                    lancer_autom_AX12();
                    break;
            }
    }
    
}
// 
//void funny_action_lancement()
// {
//    angle_AX12(3, 512, 150, SANS_ATTENTE);
// }
// 
// void funny_action_rechargement()
// {
//    angle_AX12(3, 400, 150, SANS_ATTENTE);
// }