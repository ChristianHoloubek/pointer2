#include <stdio.h>

void note_hinzufuegen(int noten[], int *panzahl);

void noten_anzeigen(int noten[], int anzahl);

float durchschnitt(int noten[], int anzahl);

int beste_note(int noten[], int anzahl);

int schlechteste_note(int noten[], int anzahl);


int main(void){
    int noten[100];
    int anzahl=0;
    char bed='\0';

    while(bed!='q'){
        printf("Waehle:\nh for hinzufuegen\na for alle anzeigen\nd for Durchschnitt\nb for beste note\ns fuer schlechteste\nq zum beenden ");
        scanf(" %c", &bed);
        switch (bed){
            case 'h':
            note_hinzufuegen(noten, &anzahl);
            break;
            case 'a':
            noten_anzeigen(noten,anzahl);

            break;
            case 'd':
            printf("Der Durhschnitt betraegt %.2f\n", durchschnitt(noten,anzahl));

            break;
            case'b':
            printf("Die beste Note ist%d\n", beste_note(noten,anzahl));


            break;
            case's':
            printf("Die schlechteste Note ist%d\n", schlechteste_note(noten,anzahl));

            break;
            case'q':
            return 0;
            default:
            printf("Invalid command");
        }
    
    }
    

    

    

    return 0;
}

void note_hinzufuegen(int noten[], int *panzahl){
    printf("Bitte Note 1-5 eingeben: ");
    scanf("%d", &noten[*panzahl]);
        
    (*panzahl) ++;

}
void noten_anzeigen(int noten[], int anzahl){
    for(int i=0; i< anzahl; i++){
        printf("%d\n", noten[i]);
    }
      
}
float durchschnitt(int noten[], int anzahl){
    float erg=0;
    if(anzahl == 0){
    return 0;}

    for(int i=0; i< anzahl; i++){
        erg+=noten[i];
    }
    
    return erg/anzahl;
}
int beste_note(int noten[], int anzahl){
    int best=noten[0];
    for(int i=0; i<anzahl; i++){
        if(noten[i]<best){
            best=noten[i];
        }

    }
    return best;
}
int schlechteste_note(int noten[], int anzahl){
    int worst=noten[0];
    for(int i=0; i<anzahl; i++){
        if(noten[i]>worst){
            worst=noten[i];
        }

    }
    return worst;

}


