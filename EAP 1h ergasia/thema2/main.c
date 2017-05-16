#include<stdio.h>
#include<conio.h>
#include<math.h>

//Dhlwsh synarthsewn
float perimetros_tetragwnou ( float pl,  float *p );
float perimetros_parallilogrammou ( float mik, float plat, float *p );
float perimetros_trigwnou ( float pleura1, float pleura2, float upot, float *p );
float perimetros_kuklou ( float r, float *p );

//Enar3h kyriws programmatos
int main( )
{
   int epilogi;

  do {
   printf("Kane mia epilogh apo tis parakatw\n");                   //Ektypwsh tou menu epilogwn
   printf("0. E3odos\n");
   printf("1. Tetragwno\n");
   printf("2. Parallhlogrammo\n");
   printf("3. Or8ogwnio Trigwno\n");
   printf("4. Kuklos\n\n");
   scanf("\n%d",&epilogi);
//Epilogh 1
   if (epilogi==1)
    {
     float pleura, perimeter;                                                     //Dhlwsh metavlhtwn
     printf ( "\nParakalw dwste th pleura tou tetragwnou: " ) ;
     scanf ( "%f", &pleura ) ;                                                    //Pairnei apo to xrhsth apo to plhktrologio to mhkos ths pleuras
     perimetros_tetragwnou( pleura, &perimeter ) ;                                //Kalei th synarthsh ypologismou ths perimetrou
     printf ( "\n H perimetros tou tetragwnou einai: %.2f\n\n", perimeter ) ;     //Epistrefei th timh ths perimetrou sth metavlhth perimeter
     getch();                                                                     //Ektypwnei mhnuma me to apotelesma me 2 dekadika
    }
//Epilogh 2
    if (epilogi== 2)
    {
        float mikos,platos,perimeter;                                               //Dhlwsh metavlhtwn
        printf("Parakalw dwste to mikos kai to platos tou parallhlogrammou: \n");
        scanf("%f %f",&mikos,&platos);                                              //Pairnei apo to xrhsth apo to plhktrologio to mhkos kai to platos
        perimetros_parallilogrammou(mikos,platos, &perimeter);                      //Kalei th synarthsh ypologismou ths perimetrou
        printf("H perimetros tou parallhlogrammou einai: %.2f\n\n",perimeter);      //Epistrefei th timh ths perimetrou sth metavlhth perimeter
        getch();                                                                    //Ektypwnei mhnuma me to apotelesma me 2 dekadika
    }
//Epilogh 3
     if (epilogi==3)
    {
        float pl1,pl2,x;                                                            //Dhlwsh metavlhtwn
        float perimeter;
        float upoteinousa;
        printf("Parakalw dwste to mhkos twn duo ka8etwn pleurwn: \n");
        scanf("%f %f",&pl1,&pl2);                                                  //Pairnei apo to xrhsth apo to plhktrologio to mhkos twn pleurwn
        x=pl1*pl1+pl2*pl2;;
        upoteinousa= sqrt(x);                                                      //Ypologismos ths ypoteinousas pleuras
        perimetros_trigwnou(pl1,pl2,upoteinousa, &perimeter);                      //Kalei th synarthsh ypologismou ths perimetrou
        printf("H perimetros tou or8ogwniou trigwnou einai: %.2f\n\n",perimeter);  //Epistrefei th timh ths perimetrou sth metavlhth perimeter
        getch();                                                                   //Ektypwnei mhnuma me to apotelesma me 2 dekadika
       }
//Epilogh 4
     if (epilogi==4)
    {
     float aktina ;                                                             //Dhlwsh metavlhtwn
     float  perimeter ;
     printf("Parakalw dwste tin aktina tou kuklou: \n");
     scanf("%f",&aktina);                                                       //Pairnei apo to xrhsth apo to plhktrologio thn aktina
     perimetros_kuklou ( aktina,  &perimeter ) ;                                //Kalei th synarthsh ypologismou ths perimetrou
     printf("H perimetros tou kuklou einai: %.2f\n\n",perimeter);               //Epistrefei th timh ths perimetrou sth metavlhth perimeter
     getch();                                                                   //Ektypwnei mhnuma me to apotelesma me 2 dekadika
    }
   } while (epilogi != 0);                                                      //Otan ginei 0 h epilogh termatizetai to programma
   printf("\n Epile3ate e3odo, sas euxaristoume\n");
   return 0;
}
float perimetros_tetragwnou ( float pl,  float *p )                           //Synarthsh ypologismou perimetrou tou tetragwnou
{                                                                             //Pairnei san eisodo th pleura k epistrefei apotelesma
    *p = pl*4 ;                                                              //th perimetro
    return (0);
}

float perimetros_parallilogrammou ( float mik, float plat, float *p )           //Synarthsh ypologismou perimetrou tou parallhlogrammou
{                                                                               //Pairnei san eisodo to mhkos kai to platos
    *p = 2*mik+2*plat ;                                                         //epistrefei san apotelema th perimetro
    return (0);
}

float perimetros_trigwnou ( float pleura1, float pleura2, float upot, float *p )    //Synarthsh ypologismou perimetrou tou trigwnou
{                                                                                   //pairnei san eisodo tis treis pleures kai
    *p = pleura1+pleura2+upot ;                                                     //epistrefei san apotelesma th perimetro
    return (0);
}

float perimetros_kuklou ( float r, float *p )                                 //Synarthsh ypologismou perimetrou tou kuklou
{                                                                         //pairnei san eisodo thn aktina tou kuklou kai
    *p = 2 * 3.14 * r ;                                                   //epistrefei san apotelesma th perimetro
    return (0);
}

