#include <stdio.h>
#include <math.h>
#include <conio.h>


int main()                                                                  //Enar3h kuriws programmatos
{
    const int x=2;                                                          //Dhlwsh statheras
    int i,j,trexon,upol;                                                    //Dhlwsh metavlhtwn
    char binary[20];
    printf("Parakalw dwste ena 8etiko akeraio ari8mo:\n");
    scanf("%d",&trexon);                                                    //Plhktrologhsh apo ton xrhsth enos arithmou
    while (trexon!=0)                                                       //An o arithmos den einai 0 trexei to programma diaforetika termatizei
    {
        if (trexon>0)
        {
            int n=trexon;                                                   //Dhlwsh metavlhths n na pairnei th timh tou arithmou pou edwse o xrhsths
            i=0;                                                            //Arxikopoihsh ths metavlhths i
            while (trexon>0)                                                //Periptwsh pou o arithmos einai thetikos
            {
                upol=trexon%x;                                              //Vriskw ypoloipo diaireshs me th stathera
                upol==1 ? (binary[i]='1') : (binary[i]='0');                //Vazei ston pinaka binary '1' h '0' analogws an einai alhthes
               // putchar(binary[i]);                                       //h oxi h entolh to upoloipo na isoutai me '1'
                trexon=trexon/x;                                            //O trexon arithmos pairnei nea timh afou diairethei me th stathera
                i++;                                                        //Au3hsh tou i kata 1 kai epistrofh sto while mexri na ginei pseudes to while>0
            }
            printf("\nO diadikos arithmos tou %d einai:\n",n);
            for (j=i-1; j>=0; j--)                                          //Epanalhpsh gia ektypwsh diadikou arithmou
            {                                                               //Apo to pio ashmanto de3iotero bit pros ta aristera
                putchar(binary[j]);
            }
            printf("\nO antestramenos diadikos tou %d einai:\n",n);
            for (j=0; j<i; j++)                                             //Epanalhpsh gia ektypwsh antestramenou diadikou arithmou
            {
                putchar(binary[j]);
            }
            printf("\n\n");
        }
        else if (trexon<0)                                                  //Periptwsh pou o arithmos einai arnhtikos
        {
            printf("O ari8mos pou edwses den einai 8etikos!\n\n");
        }
        printf("Parakalw dwste ena 8etiko akeraio ari8mo:\n");
        scanf("%d",&trexon);
    }                                                                        //H timh sto arxiko while einai ish me 0.
    printf("Telos programmatos");                                            //Den mpainei mesa sth while erxetai edw ektypwnei to mhnuma
    getch();                                                                 //Kai termatizei to programma
    return 0;
}
