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

/******************************************************************************/
/******************************************************************************/
/******************************************************************************/

void attendre(uint32_t ms)
{
    uint32_t temp = CPT_TEMPS_MATCH.t_ms;
    while(CPT_TEMPS_MATCH.t_ms - temp < ms); 
}


//#define STRAT
void strategie()
{
    
#ifdef GROS_ROBOT

    
//    EVITEMENT_ADV.mode = EVITEMENT_NORMAL;
    //EVITEMENT_ADV.mode = ACTION_EVITEMENT;
    EVITEMENT_ADV.actif = OFF;
    EVITEMENT_ADV.mode = STOP;
    
    COULEUR = couleur_depart();
    //arrière du robot au milieu init : 170-26 = 144
    init_AX12();
    init_position_robot(170, 485, 0.); // position du centre de la plaque des roues
    calage_X(144, 0, MARCHE_ARRIERE, 10);
    calage_Y(485, 0, MARCHE_ARRIERE, 10);
    rejoindre(280, 485, MARCHE_AVANT, 10);
    orienter(35, 50);
    avancer_reculer(80, 50);
    orienter(25, 50);
    avancer_reculer(-140, 50);
//    EVITEMENT_ADV.actif = ON;
    
     
    while(1){
        if(SYS_JACK){
            CPT_TEMPS_MATCH.actif = true;
            if(COULEUR == VERT){
                //
                //ABEILLE//
                passe_part(600,845,MARCHE_AVANT,50,DEBUT_TRAJECTOIRE); //chemin vers l'abeille
                passe_part(600, 1350, MARCHE_AVANT, 50, FIN_TRAJECTOIRE); 
//                EVITEMENT_ADV.actif = OFF; //détection possible de l'abeille à essayer sans
                angle_AX12(BRAS_GAUCHE, BRAS_GAUCHE_O, 250, SANS_ATTENTE);
                passe_part(600, 1450, MARCHE_AVANT, 50, DEBUT_TRAJECTOIRE); 
                passe_part(225, 1600, MARCHE_AVANT, 50, FIN_TRAJECTOIRE); 
                orienter(-90, 50);//orientation pour l'abeille
                calage(-400, 25);
                angle_AX12(BRAS_GAUCHE, BRAS_GAUCHE_F, 250, SANS_ATTENTE);
                attendre(6000);
                EVITEMENT_ADV.actif = ON;
                rejoindre(225, 1700, MARCHE_AVANT, 50);
                orienter(-80, 50);
                rejoindre(250, 1600, MARCHE_AVANT, 50);
                orienter(0, 50);
                calage_X(144, 0, MARCHE_ARRIERE, 10);   
        //            orienter(-60, 50);
        //            rejoindre()
                passe_part(400, 1600, MARCHE_AVANT, 50, DEBUT_TRAJECTOIRE);
                passe_part(600, 1400, MARCHE_AVANT, 50, MILIEU_TRAJECTOIRE);
                passe_part(600,845,MARCHE_AVANT,50,FIN_TRAJECTOIRE); //position reservoir d'eau
                //
                orienter(0, 50); //orientation pour la recuperation des balles
                EVITEMENT_ADV.actif = OFF; //détection possible du résevoir
                rejoindre(140,845,MARCHE_ARRIERE,50);//position pour les récupérer
                //
                //RECUPERATION DES BALLES//
                recuperation_balles();
        //            rejoindre(510,840,MARCHE_AVANT,50);//position réservoir à eau
                //
                EVITEMENT_ADV.actif = ON;
                rejoindre(900,845,MARCHE_AVANT,50);//position réservoir à eau
                orienter(90, 50);
                //
                //CUBES//
                passe_part(830, 200, MARCHE_ARRIERE, 50, DEBUT_TRAJECTOIRE);//cubes
                passe_part(830, 600, MARCHE_AVANT, 50, FIN_TRAJECTOIRE);
                //
                //INTERRUPTEUR//
//                interrupteur();
                //
                //¨TIR BALLES//
                depot_balles();
            }
            if(COULEUR == ORANGE){
                
                passe_part(600,845,MARCHE_AVANT,50,DEBUT_TRAJECTOIRE);//position chateau d'eau pour abeille
                passe_part(600, 1350, MARCHE_AVANT, 50, FIN_TRAJECTOIRE);
                EVITEMENT_ADV.actif = OFF;
                angle_AX12(BRAS_DROIT, BRAS_DROIT_O, 250, SANS_ATTENTE);
                passe_part(600, 1450, MARCHE_AVANT, 50, DEBUT_TRAJECTOIRE);
                passe_part(225, 1600, MARCHE_AVANT, 50, FIN_TRAJECTOIRE);
                orienter(-90, 50);
                calage(-400, 25);
                angle_AX12(BRAS_DROIT, BRAS_DROIT_F, 250, SANS_ATTENTE);
                attendre(6000);
                EVITEMENT_ADV.actif = ON;


                rejoindre(225, 1700, MARCHE_AVANT, 50);
                orienter(-80, 50);
                rejoindre(250, 1600, MARCHE_AVANT, 50);
                orienter(0, 50);
                calage_X(144, 0, MARCHE_ARRIERE, 10);   
    //            orienter(-60, 50);
    //            rejoindre()
                passe_part(400, 1600, MARCHE_AVANT, 50, DEBUT_TRAJECTOIRE);
                passe_part(600, 1400, MARCHE_AVANT, 50, MILIEU_TRAJECTOIRE);
                passe_part(600,845,MARCHE_AVANT,50,FIN_TRAJECTOIRE);
                //
                //
                orienter(0, 50);
                EVITEMENT_ADV.actif = OFF;
                rejoindre(155,845,MARCHE_ARRIERE,50);//réservoir à eau //148 //835
                //
                //ouverture du loquet et récupération des balles
                recuperation_balles();
    //            rejoindre(510,840,MARCHE_AVANT,50);//position réservoir à eau
                //
                //interrupteur
                rejoindre(900,845,MARCHE_AVANT,50);//position réservoir à eau
                orienter(90, 50);

                passe_part(830, 200, MARCHE_ARRIERE, 50, DEBUT_TRAJECTOIRE);//cubes
                passe_part(830, 600, MARCHE_AVANT, 50, FIN_TRAJECTOIRE);
//                interrupteur();

                //
                //tir des balles
                depot_balles();
                
            }
        }
    }
#endif

#ifdef PETIT_ROBOT
    
    EVITEMENT_ADV.actif = OFF;
    EVITEMENT_ADV.mode = STOP;
    
    COULEUR = couleur_depart();
    init_AX12();
    init_position_robot(127., 125., 180.); 
    calage_X(101, 180, MARCHE_AVANT,50);
    
    calage_Y(122, 180, MARCHE_AVANT, 25);
    rejoindre(176,122,MARCHE_ARRIERE,25);
    orienter(190,205);
    
    
    while(1){
        if(!CAPTEUR8){ //orange est le bouton vert
            CPT_TEMPS_MATCH.actif = true;
            if(COULEUR == ORANGE){//côté vert
                //Interrupteur (1135 au milieu et 85 pour chaque côté)
                interrupteur();
                
                //Récupération de balles
                angle_AX12(LOQUET, LOQUET_G, 100, SANS_ATTENTE);
                EVITEMENT_ADV.actif = ON;
                EVITEMENT_ADV.mode = STOP;
                passe_part(1321, 550, MARCHE_ARRIERE, 50, DEBUT_TRAJECTOIRE);
                passe_part(2486, 1400, MARCHE_ARRIERE, 50, FIN_TRAJECTOIRE);
//                do
//                {
//                    EVITEMENT_ADV.actif = ON;
//                    EVITEMENT_ADV.mode = ACTION_EVITEMENT;
//                    passe_part(1321, 550, MARCHE_ARRIERE, 50, DEBUT_TRAJECTOIRE);
//                    passe_part(2456, 1400, MARCHE_ARRIERE, 50, FIN_TRAJECTOIRE);
//                }while(EVITEMENT_ADV.mode != ACTION_EVITEMENT);
                 
            
                EVITEMENT_ADV.actif = OFF;
                orienter(-90, 25);
                avancer_reculer(-340, 20);//-400
                angle_AX12(LOQUET, LOQUET_D, 100, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                avancer_reculer(1, 50);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                EVITEMENT_ADV.actif = ON;
                avancer_reculer(225, 20);
                EVITEMENT_ADV.actif = OFF;

                //Dépose de balles 1
                angle_AX12(LOQUET, LOQUET_G, 100, SANS_ATTENTE);
                
                orienter(0, 50); 
                //angle_AX12(LOQUET, LOQUET_D, 100, SANS_ATTENTE);
                EVITEMENT_ADV.actif = OFF;
//                EVITEMENT_ADV.cote = EV_GAUCHE;
                avancer_reculer(-400, 50);
                avancer_reculer(-400, 50);
//                EVITEMENT_ADV.cote = EV_TOTALE;
                
                avancer_reculer(250, 50);
               

//                EVITEMENT_ADV.actif = OFF;
                
                orienter(-90, 50);

                avancer_reculer(-500, 50);
                calage_teta(-90, MARCHE_ARRIERE, 50);
                
                angle_AX12(BAC, BAC_D, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_INT, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_D, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_INT, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_D, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_I, 100, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                avancer_reculer(1, 50); avancer_reculer(1, 50);

                avancer_reculer(200, 50);
                angle_AX12(LOQUET, LOQUET_D, 100, SANS_ATTENTE);
                orienter(0, 50);
//                EVITEMENT_ADV.actif = ON;
//                EVITEMENT_ADV.cote = EV_GAUCHE;
                avancer_reculer(-300, 50);
                
                avancer_reculer(150, 50);
                EVITEMENT_ADV.actif = OFF;
                orienter(-90, 50);
//                EVITEMENT_ADV.actif = ON;
//                EVITEMENT_ADV.cote = EV_TOTALE;
                calage_teta(-90, MARCHE_ARRIERE, 50);
                avancer_reculer(-400, 50);
                angle_AX12(BAC, BAC_D, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_INT, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_D, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_INT, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_D, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_I, 100, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
//                EVITEMENT_ADV.actif = ON;
                avancer_reculer(200, 50);
                orienter(180, 50);
                avancer_reculer(-200, 50);
                orienter(-90, 50);
                calage_teta(-90, MARCHE_ARRIERE, 50);
                avancer_reculer(-400, 50);
                
                while(1){
                    angle_AX12(BAC, BAC_D, 200, SANS_ATTENTE);
                    avancer_reculer(1, 50); avancer_reculer(1, 50);
                    angle_AX12(BAC, BAC_INT, 200, SANS_ATTENTE);
                    avancer_reculer(1, 50); avancer_reculer(1, 50);
                }
            }
            if(COULEUR == VERT){ //côté orange
                //Interrupteur (1135 au milieu et 85 pour chaque côté)
                interrupteur();
                
                //Récupération de balles
                angle_AX12(LOQUET, LOQUET_G, 100, SANS_ATTENTE);
                EVITEMENT_ADV.actif = ON;
                EVITEMENT_ADV.mode = STOP;
                passe_part(1321, 550, MARCHE_ARRIERE, 50, DEBUT_TRAJECTOIRE);
                passe_part(2446, 1400, MARCHE_ARRIERE, 50, FIN_TRAJECTOIRE);
//                do
//                {
//                    EVITEMENT_ADV.actif = ON;
//                    EVITEMENT_ADV.mode = ACTION_EVITEMENT;
//                    passe_part(1321, 550, MARCHE_ARRIERE, 50, DEBUT_TRAJECTOIRE);
//                    passe_part(2456, 1400, MARCHE_ARRIERE, 50, FIN_TRAJECTOIRE);
//                }while(EVITEMENT_ADV.mode != ACTION_EVITEMENT);
            
                EVITEMENT_ADV.actif = OFF;
                orienter(-90, 25);
                avancer_reculer(-420, 20);//à modifier
                angle_AX12(LOQUET, LOQUET_D, 100, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                avancer_reculer(1, 50);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                EVITEMENT_ADV.actif = ON;
                avancer_reculer(300, 20);
                EVITEMENT_ADV.actif = OFF;

                //Dépose de balles 1
                angle_AX12(LOQUET, LOQUET_G, 100, SANS_ATTENTE);
                

                orienter(0, 50);
//                EVITEMENT_ADV.actif = ON;
//                EVITEMENT_ADV.cote = EV_GAUCHE;

                avancer_reculer(-400, 50);
                avancer_reculer(-450, 50);
                EVITEMENT_ADV.actif = ON;
//                EVITEMENT_ADV.cote = EV_TOTALE;
                avancer_reculer(300, 50);

                EVITEMENT_ADV.actif = OFF;

                orienter(-90, 50);


                avancer_reculer(-300, 50);
                
                calage_teta(-90, MARCHE_ARRIERE, 50);
                
                angle_AX12(BAC, BAC_D, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_INT, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_D, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_INT, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_D, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_I, 100, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                avancer_reculer(1, 50); avancer_reculer(1, 50);

                avancer_reculer(125, 50);
                angle_AX12(LOQUET, LOQUET_D, 100, SANS_ATTENTE);
                
                orienter(0, 50);
//                EVITEMENT_ADV.actif = ON;
//                EVITEMENT_ADV.cote = EV_GAUCHE;
                avancer_reculer(-300, 50);
//                EVITEMENT_ADV.cote = EV_TOTALE;
                avancer_reculer(150, 50);
                orienter(-90, 50);
                EVITEMENT_ADV.actif = OFF;
                avancer_reculer(-300, 50);
                calage_teta(-90, MARCHE_ARRIERE, 50);
                avancer_reculer(-400, 50);
                angle_AX12(BAC, BAC_D, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_INT, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_D, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_INT, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_D, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_I, 100, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                avancer_reculer(200, 50);
                angle_AX12(LOQUET, LOQUET_D, 100, SANS_ATTENTE);
                orienter(0, 50);
//                EVITEMENT_ADV.actif = ON;
//                EVITEMENT_ADV.cote = EV_GAUCHE;
                avancer_reculer(-300, 50);
                
                avancer_reculer(150, 50);
                EVITEMENT_ADV.actif = OFF;
                orienter(-90, 50);
//                EVITEMENT_ADV.actif = ON;
//                EVITEMENT_ADV.cote = EV_TOTALE;
                calage_teta(-90, MARCHE_ARRIERE, 50);
                avancer_reculer(-400, 50);
                angle_AX12(BAC, BAC_D, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_INT, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_D, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_INT, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_D, 200, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                angle_AX12(BAC, BAC_I, 100, SANS_ATTENTE);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
                avancer_reculer(1, 50); avancer_reculer(1, 50);
//                EVITEMENT_ADV.actif = ON;
                avancer_reculer(200, 50);
                orienter(180, 50);
                avancer_reculer(-200, 50);
                orienter(-90, 50);
                calage_teta(-90, MARCHE_ARRIERE, 50);
                avancer_reculer(-400, 50);
                
                while(1){
                    angle_AX12(BAC, BAC_D, 200, SANS_ATTENTE);
                    avancer_reculer(1, 50); avancer_reculer(1, 50);
                    angle_AX12(BAC, BAC_INT, 200, SANS_ATTENTE);
                    avancer_reculer(1, 50); avancer_reculer(1, 50);
                }
            }
        }
    }
        
#endif
}


void homologation()
{   
#ifdef GROS_ROBOT

    
//    EVITEMENT_ADV.mode = EVITEMENT_NORMAL;
    //EVITEMENT_ADV.mode = ACTION_EVITEMENT;
    EVITEMENT_ADV.actif = OFF;
    EVITEMENT_ADV.mode = STOP;
    
    COULEUR = couleur_depart();
    //arrière du robot au milieu init : 170-26 = 144
    init_AX12();
    init_position_robot(170, 485, 0.); // position du centre de la plaque des roues
    calage_X(144, 0, MARCHE_ARRIERE, 10);
    calage_Y(485, 0, MARCHE_ARRIERE, 10);
    rejoindre(280, 485, MARCHE_AVANT, 10);
    orienter(35, 50);
    avancer_reculer(80, 50);
    orienter(25, 50);
    avancer_reculer(-140, 50);
    EVITEMENT_ADV.actif = ON;
     
    while(1){
        if(SYS_JACK){
//            rejoindre(600,835,MARCHE_AVANT,50);//position chateau d'eau si que château d'eau
//            if (COULEUR == VERT){
//                angle_AX12(BRAS_GAUCHE, BRAS_GAUCHE_O, 100, SANS_ATTENTE);
//            }
//            else {
//                angle_AX12(BRAS_DROIT, BRAS_DROIT_O, 100, SANS_ATTENTE);
//            }
//            passe_part(600,835,MARCHE_AVANT,75,DEBUT_TRAJECTOIRE);//position chateau d'eau pour abeille
//            passe_part(600, 1350, MARCHE_AVANT, 75, FIN_TRAJECTOIRE);
//            EVITEMENT_ADV.actif = OFF;
//            passe_part(600, 1450, MARCHE_AVANT, 75, DEBUT_TRAJECTOIRE);
//            passe_part(225, 1600, MARCHE_AVANT, 75, FIN_TRAJECTOIRE);
//            orienter(-90, 50);
//            avancer_reculer(-400, 50);
//            if (COULEUR == VERT){
//                angle_AX12(BRAS_GAUCHE, BRAS_GAUCHE_F, 100, SANS_ATTENTE);
//            }
//            else {
//                angle_AX12(BRAS_DROIT, BRAS_DROIT_F, 100, SANS_ATTENTE);
//            }
//            avancer_reculer(1, 50); avancer_reculer(-1, 50);
//            avancer_reculer(1, 50); avancer_reculer(-1, 50);
//            avancer_reculer(1, 50); avancer_reculer(-1, 50);
//            avancer_reculer(1, 50); avancer_reculer(-1, 50);
//            avancer_reculer(1, 50); avancer_reculer(-1, 50);
//            EVITEMENT_ADV.actif = ON;
//
//            
//            rejoindre(225, 1700, MARCHE_AVANT, 50);
//            orienter(-80, 50);
//            rejoindre(250, 1600, MARCHE_AVANT, 50);
//            orienter(0, 50);
//            calage_X(144, 0, MARCHE_ARRIERE, 10);   
////            orienter(-60, 50);
////            rejoindre()
//            passe_part(400, 1600, MARCHE_AVANT, 50, DEBUT_TRAJECTOIRE);
//            passe_part(600, 1400, MARCHE_AVANT, 50, MILIEU_TRAJECTOIRE);
//            passe_part(600,835,MARCHE_AVANT,50,FIN_TRAJECTOIRE);
            rejoindre(600, 835, MARCHE_AVANT,50);//chateau d'eau sans abeille
            //
            //
            orienter(0, 50);
            EVITEMENT_ADV.actif = OFF;
            rejoindre(148,835,MARCHE_ARRIERE,50);//réservoir à eau //148
            //
            //ouverture du loquet et récupération des balles
            recuperation_balles();
//            rejoindre(510,840,MARCHE_AVANT,50);//position réservoir à eau
            //
            //interrupteur
            rejoindre(900,840,MARCHE_AVANT,50);//position réservoir à eau
            orienter(90, 50);

            passe_part(850, 200, MARCHE_ARRIERE, 50, DEBUT_TRAJECTOIRE);//cubes
            passe_part(850, 600, MARCHE_AVANT, 50, FIN_TRAJECTOIRE);
            orienter(0, 50);
            rejoindre(1135, 600, MARCHE_AVANT, 50);
            orienter(-90,50);
            avancer_reculer(400, 50);
//            EVITEMENT_ADV.actif = OFF; //détection du mur et de l'interrupteur
            calage(300, 10);
            rejoindre(1135, 500, MARCHE_ARRIERE, 50);
            
            //
            //tir des balles
            depot_balles();
            //
            while(1){
                brake();
            }
        }
    }
#endif

#ifdef PETIT_ROBOT
    
    EVITEMENT_ADV.actif = ON;
    EVITEMENT_ADV.mode = STOP;
    
    COULEUR = couleur_depart();
    init_AX12();
    init_position_robot(127., 125., 180.); 
    

    calage_Y(122, 180, MARCHE_AVANT, 25);
    rejoindre(196,122,MARCHE_ARRIERE,25);
    orienter(185, 25);
    orienter(190,25);
    
    while(1){
//        if(SYS_JACK){
        
            //Interrupteur (1135 au milieu et 85 pour chaque côté)
            angle_AX12(INTERRUPTEUR, INTERRUPTEUR_O, 100, SANS_ATTENTE);//ouvre l'AX12 pour l'interrupteur
            
//            if(COULEUR == ORANGE){
//                rejoindre(1220, 340, MARCHE_ARRIERE, 50);
//            }
//            else {
                rejoindre(1085, 340, MARCHE_ARRIERE, 50);
//            }
            
            EVITEMENT_ADV.actif = OFF;
            orienter(-90, 50); //se place face à l'interrupteur
            avancer_reculer(100, 75);
            calage(300, 25); //interrupteur
            angle_AX12(INTERRUPTEUR, INTERRUPTEUR_F, 100, SANS_ATTENTE);
            //
            //Récupération de balles
            angle_AX12(LOQUET, LOQUET_G, 100, SANS_ATTENTE);
            EVITEMENT_ADV.actif = ON;
            do
            {
                EVITEMENT_ADV.mode = ACTION_EVITEMENT;
                passe_part(1321, 550, MARCHE_ARRIERE, 50, DEBUT_TRAJECTOIRE);
                passe_part(2456, 1400, MARCHE_ARRIERE, 50, FIN_TRAJECTOIRE);
            }while(EVITEMENT_ADV.mode != ACTION_EVITEMENT);
            
            EVITEMENT_ADV.actif = OFF;
            orienter(-90, 25);
            //
            //rejoindre(2400, 1900, MARCHE_ARRIERE, 20);
            avancer_reculer(-330, 20);
            //
            angle_AX12(LOQUET, LOQUET_D, 100, SANS_ATTENTE);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            //
            EVITEMENT_ADV.actif = ON;
            avancer_reculer(260, 20);

            
            //Dépose de balles 1
            angle_AX12(LOQUET, LOQUET_G, 100, SANS_ATTENTE);
            
            orienter(0, 50);
            angle_AX12(LOQUET, LOQUET_D, 100, SANS_ATTENTE);
            
            avancer_reculer(-650, 50);
            angle_AX12(LOQUET, LOQUET_G, 100, SANS_ATTENTE);
            avancer_reculer(200, 50);
            angle_AX12(LOQUET, LOQUET_D, 100, SANS_ATTENTE);
            
            orienter(-90, 50);
            angle_AX12(LOQUET, LOQUET_I, 100, SANS_ATTENTE);
            
            //
            
            avancer_reculer(-300, 50);
            calage_teta(-90, MARCHE_ARRIERE, 50);
            //
            angle_AX12(BAC, BAC_D, 100, SANS_ATTENTE);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            angle_AX12(BAC, BAC_I, 100, SANS_ATTENTE);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            //
            //Dépose de balles 2
//            rejoindre(2000, 1500, MARCHE_AVANT, 50);
//            orienter(0,50);
//            rejoindre(1500, 1500, MARCHE_ARRIERE, 50);
//            rejoindre(1650, 1500, MARCHE_AVANT, 50);
//            orienter(-90, 50);
            avancer_reculer(125, 50);
            angle_AX12(LOQUET, LOQUET_D, 100, SANS_ATTENTE);
            orienter(0, 50);
            angle_AX12(LOQUET, LOQUET_G, 100, SANS_ATTENTE);
            avancer_reculer(-300, 50);
            angle_AX12(LOQUET, LOQUET_I, 100, SANS_ATTENTE);
            avancer_reculer(150, 50);
            orienter(-90, 50);
            avancer_reculer(-300, 50);
            calage_teta(-90, MARCHE_ARRIERE, 50);
            //
            //calage_X(1900,-90, MARCHE_ARRIERE, 50);
            avancer_reculer(-400, 50);
            //
            angle_AX12(BAC, BAC_D, 100, SANS_ATTENTE);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            angle_AX12(BAC, BAC_I, 100, SANS_ATTENTE);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            avancer_reculer(1, 50); avancer_reculer(1, 50);
            while(1){
                brake();
            }
//        }
    }
    
    brake();
        
#endif
}

void recuperation_balles(){
#ifdef GROS_ROBOT
    //ouverture du loquet et récupération des balles
    angle_AX12(LOQUET, LOQUET_O, 100, SANS_ATTENTE); 
    //attente de l'AX12 et des balles
    avancer_reculer(25, 25); avancer_reculer(-25, 25);
    orienter(5,10);orienter(-5,10);
    avancer_reculer(25, 25); avancer_reculer(-25, 25);
    orienter(5,10);orienter(-5,10);
    avancer_reculer(25, 25); avancer_reculer(-25, 25);
    orienter(5,10);orienter(-5,10);
    avancer_reculer(25, 25); avancer_reculer(-25, 25);
    orienter(5,10);orienter(-5,10);
#endif
#ifdef PETIT_ROBOT
#endif
}

void init_AX12(){
#ifdef GROS_ROBOT
    //BRAS GAUCHE    
    angle_AX12(BRAS_GAUCHE, BRAS_GAUCHE_F, 100, SANS_ATTENTE);
    //BRAS DROIT
    angle_AX12(BRAS_DROIT, BRAS_DROIT_F, 100, SANS_ATTENTE);
    //PORTE_CANON
    angle_AX12(PORTE_CANON, PORTE_CANON_F, 100, SANS_ATTENTE);
    //LOQUET
    angle_AX12(LOQUET, LOQUET_I, 100, SANS_ATTENTE);
#endif
#ifdef PETIT_ROBOT
    //INTERRUPTEUR
    angle_AX12(INTERRUPTEUR, INTERRUPTEUR_F, 100, SANS_ATTENTE);
    //LOQUET
    angle_AX12(LOQUET, LOQUET_I, 100, SANS_ATTENTE);
    //BAC
    angle_AX12(BAC, BAC_I, 100, SANS_ATTENTE);
#endif
}

void depot_balles(){
#ifdef GROS_ROBOT
    EVITEMENT_ADV.actif = OFF; //détection du chateau d'eau
    if(COULEUR == VERT){
        rejoindre(485,375,MARCHE_AVANT,50);//465.355 trop loin x trop grand
        while(1){
            orienter(-125,50);  
            avancer_reculer(5, 100); avancer_reculer(-5, 100);
            avancer_reculer(5, 100); avancer_reculer(-5, 100);
            avancer_reculer(5, 100); avancer_reculer(-5, 100);
            avancer_reculer(5, 100); avancer_reculer(-5, 100);
            avancer_reculer(5, 100); avancer_reculer(-5, 100);
        }
    }
    if(COULEUR == ORANGE){
        rejoindre(485,375,MARCHE_AVANT,50);//465.355 trop loin x trop grand
        while(1){
            orienter(-115.,50);  
            avancer_reculer(5, 100); avancer_reculer(-5, 100);
            avancer_reculer(5, 100); avancer_reculer(-5, 100);
            avancer_reculer(5, 100); avancer_reculer(-5, 100);
            avancer_reculer(5, 100); avancer_reculer(-5, 100);
            avancer_reculer(5, 100); avancer_reculer(-5, 100);
        }
    }
#endif
#ifdef PETIT_ROBOT
#endif
}

void interrupteur(){
#ifdef GROS_ROBOT
    if (COULEUR == VERT){
                        //INTERRUPTEUR
//                orienter(0, 50);
//
//                rejoindre(1135, 600, MARCHE_AVANT, 50);//vert x plus petit
//                orienter(-90,50);
//                avancer_reculer(400, 50);
//
//                EVITEMENT_ADV.actif = OFF; //détection du mur et de l'interrupteur
//                calage(300, 50);
//                rejoindre(1135, 500, MARCHE_ARRIERE, 50);

    }
    if (COULEUR == ORANGE){
        //INTERRUPTEUR
//                orienter(0, 50);
//
//                rejoindre(1135, 600, MARCHE_AVANT, 50);//vert x plus petit
//                orienter(-90,50);
//                calage(400, 50);
//
//                EVITEMENT_ADV.actif = OFF; //détection du mur et de l'interrupteur
//                calage(300, 10);
//                rejoindre(1135, 500, MARCHE_ARRIERE, 50);
    }
#endif
#ifdef PETIT_ROBOT
    if (COULEUR == VERT){
        angle_AX12(INTERRUPTEUR, INTERRUPTEUR_O, 100, SANS_ATTENTE);//ouvre l'AX12 pour l'interrupteur

        rejoindre(1240, 340, MARCHE_ARRIERE, 50); //1235

                
        // TEMPO TEST 
//                attendre(5000);
        // TEMPO TEST
                
    
        EVITEMENT_ADV.actif = OFF;
        orienter(-90, 50); //se place face à l'interrupteur
        avancer_reculer(300, 7-5);
        calage(100, 25); //interrupteur
        angle_AX12(INTERRUPTEUR, INTERRUPTEUR_F, 100, SANS_ATTENTE);
    }
    if (COULEUR == ORANGE){
        angle_AX12(INTERRUPTEUR, INTERRUPTEUR_O, 100, SANS_ATTENTE);//ouvre l'AX12 pour l'interrupteur
               
        rejoindre(1108, 340, MARCHE_ARRIERE, 50); //1108


        // TEMPO TEST 
//                attendre(5000);
        // TEMPO TEST 


        EVITEMENT_ADV.actif = OFF;
        orienter(-90, 50); //se place face à l'interrupteur
        avancer_reculer(300, 75);
        calage(100, 25); //interrupteur

        angle_AX12(INTERRUPTEUR, INTERRUPTEUR_F, 100, SANS_ATTENTE);
    }
#endif
}