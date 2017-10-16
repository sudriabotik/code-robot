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

int offset_front = 150;//270;
int offset_side = 165;
int vitesse_calage = 30;
int vitesse_std = 95;
int vitesse_passe_part = 75;
int i =0;


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
    //  22      av droit billes 
    //  23      bielle droite
    //  26      bielle gauche
    
    CPT_TEMPS_MATCH.actif = true;
    EVITEMENT_ADV.actif = OFF;
    //EVITEMENT_ADV.mode = STOP;
    
    /**************************** INITIALISATION ******************************/
    init_position_robot(330./2.0+24.0, 76.65, 0.); //  189?
    mvt_cube(RENTRER);
    uint32_t temp = CPT_TEMPS_MATCH.t_ms;
    while(CPT_TEMPS_MATCH.t_ms - temp < 5000);
    EVITEMENT_ADV.actif = OFF;
    mvt_cage_bille(AR, lever);   
    
    // Passage bascule
    FLAG_ACTION = PASSAGE_BASCULE;
    rejoindre(975, 76.65, MARCHE_AVANT, 40);
    mvt_cage_bille(AR, abaisser);
    orienter(45, 40);
    temp = CPT_TEMPS_MATCH.t_ms;
    while( ( (CPT_TEMPS_MATCH.t_ms - temp) < 16000 ) || (FLAG_ACTION == PASSAGE_BASCULE));
    
    /* Init moteur : aspiration avant + non-expulsion arrière */
    alimenter_moteur_Y(ON, MARCHE_AVANT);
    envoit_pwm(MOTEUR_X, -10.0);
    
    
    
    //Récup gros cratère 
    if(FLAG_ACTION != PASSAGE_BASCULE)
        EVITEMENT_ADV.actif = ON;
    passe_part(1200,700, MARCHE_AVANT, 50, DEBUT_TRAJECTOIRE);
    passe_part(900,1000, MARCHE_AVANT, 50, MILIEU_TRAJECTOIRE);
    passe_part(550, 1370, MARCHE_AVANT, 40, FIN_TRAJECTOIRE);
    
    EVITEMENT_ADV.actif = OFF;
    
    orienter(135,50);
    mvt_cage_bille(AV, lever);
    avancer_reculer(75,30);
    
    mvt_cube(SORTIR);
    delay_ms(1000);
    mvt_cube(RENTRER);
    
    /*
    orienter(160, 10);   //135 + 35
    mvt_cube(SORTIR);
    delay_ms(1000);
    mvt_cube(RENTRER);
    */
   
    
    orienter(110, 10); // 135 - 35
    mvt_cube(SORTIR);
    delay_ms(1000);
    mvt_cube(RENTRER);
    
    orienter(135, 30);
    
    EVITEMENT_ADV.actif = ON;

    // Boite rentrée
    avancer_reculer(-140,50);
    
    mvt_cage_bille(AV, abaisser);
    //rejoindre(350,480, MARCHE_ARRIERE, 30);
    rejoindre(370,480, MARCHE_ARRIERE, 30);

    EVITEMENT_ADV.actif = OFF;

    orienter(90, 30);
    calage_Y(388, 90, -1, 20);
    
    // ajustement pour tirer au milieu de la cage
    avancer_reculer(35,50);
    orienter(85, 30);

    
    //Sniper cage
    //rejoindre(950,700, MARCHE_ARRIERE, 40); ???
    delay_ms(500);
    
    // Expulsion arrière
    //envoit_pwm(MOTEUR_X, -20.0);
    //delay_ms(200);
    
    /*
    envoit_pwm(MOTEUR_X, 43.0);
    delay_ms(3000);
    envoit_pwm(MOTEUR_X, -30.0);
    delay_ms(500);
    envoit_pwm(MOTEUR_X, 43.0);
    delay_ms(2500);
    envoit_pwm(MOTEUR_X, -30.0);
    delay_ms(500);
    envoit_pwm(MOTEUR_X, 43.0);
    delay_ms(3500);    
    envoit_pwm(MOTEUR_X, -30.0);
    */
    
    decrease_speed();
    increase_speed();    
    decrease_speed();
    increase_speed();    
    decrease_speed();
    increase_speed();

    for(i=0;i<30;i++) 
    {
        envoit_pwm(MOTEUR_X,1-i);
        delay_ms(10);
    }
    
    /* Récup petit cratère 1*/
    
    EVITEMENT_ADV.actif = ON;

    avancer_reculer(80,100);
    orienter(0, 100);
    avancer_reculer(100,100);
    mvt_cube(SORTIR);
    
    delay_ms(2000);
    
    mvt_cube(RENTRER);
    avancer_reculer(-100, 100);
    orienter(85, 100);
    
    calage_Y(388, 90, -1, 20);
    
    // ajustement pour tirer au milieu de la cage
    avancer_reculer(35,50);
    orienter(85, 30);
     
   
    // Expulsion arrière
    //envoit_pwm(MOTEUR_X, -20.0);
    //delay_ms(200);
    
    /*
    envoit_pwm(MOTEUR_X, 43.0);
    delay_ms(3000);

    envoit_pwm(MOTEUR_X, -30.0);
    delay_ms(500);

    envoit_pwm(MOTEUR_X, 43.0);
    delay_ms(3000);

    envoit_pwm(MOTEUR_X, -30.0);
    delay_ms(500);

    envoit_pwm(MOTEUR_X, 43.0);
    delay_ms(4500);
    */
    
    decrease_speed();
    increase_speed();
    decrease_speed();
    increase_speed();    
    decrease_speed();
    increase_speed();


    envoit_pwm(MOTEUR_X, -30.0);
    
    /*********************************STRAT3:cratére **************************/
    /*
    rejoindre(1200,540, MARCHE_ARRIERE, 70);
    orienter(135,100);
    avancer_reculer(100,100);
    mvt_cube(SORTIR);
    delay_ms(2000);
    mvt_cube(RENTRER);
    
    avancer_reculer(-200,100);
    rejoindre(650,1000,MARCHE_AVANT, 70);
    rejoindre(400,550, MARCHE_AVANT, 70);
    calage_Y(388, 0, -1, 20);
    
    envoit_pwm(MOTEUR_X, 55.0);
    delay_ms(10000);
    envoit_pwm(MOTEUR_X, -10.0);

    
    */
    
    
    #endif
}

  void homologation()
{
    COULEUR = couleur_depart();

#ifdef GROS_ROBOT

    CPT_TEMPS_MATCH.actif = true;
    EVITEMENT_ADV.actif = ON;
    EVITEMENT_ADV.mode = STOP;

    avancer_reculer(500, 30);
    /*init_position_robot(330./2.0+30, 76.65, 0.);
    rejoindre(900, 0, 1, 30);
    orienter(90, 50);
    EVITEMENT_ADV.actif = ON;
    avancer_reculer(500, 50);*/
    funny_action_lancement();
#endif
}

void pompes(uint8_t pompe, uint8_t onOff)
{
        /*if (pompe == POMPE_DROITE)      
        {
            if(onOff == ON)
                envoit_pwm(MOTEUR_X, PWM_X_VALEUR_MAX);
            else
                envoit_pwm(MOTEUR_X, 0.);
        }
        
        else if(pompe == POMPE_GAUCHE)
        {
            alimenter_moteur_Y(onOff, MARCHE_AVANT);
        }*/
}


void moteurs(uint8_t moteur, uint8_t onOff)
{
    if(moteur == MOTEUR_DROIT)
    {
        if(onOff == ON)
            envoit_pwm(MOTEUR_X, PWM_X_VALEUR_MAX);
        else
            envoit_pwm(MOTEUR_X, 0.);
    }
    
    else if (moteur == MOTEUR_GAUCHE)
    {
        alimenter_moteur_Y(onOff, MARCHE_AVANT);
    }
}

void mvt_cube(uint8_t action)
{
    switch(action)
    {
        case SORTIR: 
            angle_AX12(23, 715, 150, AVEC_ATTENTE);
            angle_AX12(26, (1024-715), 150, AVEC_ATTENTE);
            lancer_autom_AX12();
            delay_ms(750);
            break;
        case RENTRER:
            angle_AX12(23, 160, 150, AVEC_ATTENTE);
            angle_AX12(26, (1024-160), 150, AVEC_ATTENTE);
            lancer_autom_AX12();
            delay_ms(750);
            break;
    }
}

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
                    angle_AX12(12, 512, 150, AVEC_ATTENTE); // valeur angle par défault : 512
                    lancer_autom_AX12();
                    break;
            }
    }
}
 
void funny_action_lancement()
{
    angle_AX12(3, 512, 150, SANS_ATTENTE);
}
 
void funny_action_rechargement()
{
   angle_AX12(3, 400, 150, SANS_ATTENTE);
}

void increase_speed()
{
    for(i=0;i<43;i++)
    {
        envoit_pwm(MOTEUR_X,i+1);
        delay_ms(5);
    }
    
    delay_ms(2500);

    for(i=43;i>0;i--)
    {
        envoit_pwm(MOTEUR_X,i+1);
        delay_ms(5);
    }
}



void decrease_speed()
{
    for(i=0;i<30;i++) 
    {
        envoit_pwm(MOTEUR_X,1-i);
        delay_ms(5);
    }
    
        delay_ms(10);  

     
    for(i=30;i>0;i--) 
    {
        envoit_pwm(MOTEUR_X,1-i);
        delay_ms(5);
    }
}
