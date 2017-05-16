#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define maxCapacity 53


int main()
{
    FILE *pToFile= fopen("bus.txt","r");                    //Anoigma arxeiou bus.txt gia anagnwsh pinakidas

/*Dhlwsh metavlhtwn*/
   char plateNum[7];
   int theseis;
   int bus[maxCapacity];
   int emptySeats;
   int i, j, k;
   int countEmpty;
   int selection;
   int selSeat;
   int deselSeat;
   int searchSeat;
   int corridorNum;
   int line;
   int seatNum;
   int flag;
   int reservedSeats;



/*Diavasma apo to arxeio bus.txt tis pinakidas tou lewforeiou kai tou plhthous twn thesewn tou*/
        for (i=0;i<7;i++)
        {
            fscanf(pToFile, "%c", &plateNum[i]);
        }
        printf("\t");
        fscanf(pToFile, "%d", &theseis);
        printf("\n\n");
 /*Arxikopoihsh pinaka me '0' oti arxika oles oi theseis tou lewforeiou einai kenes*/
   for (i=0; i<maxCapacity; i++)
   {
       bus[i]=0;
   }

/*¸Elegxos an o arithmos twn thesewn einai ektos oriwn*/
   if (theseis > maxCapacity)
   {
       printf ("\nO arithmos twn thesewn toy lewforeioy ypervainei ton megisto epitrepto.\n");
       exit;
   }
   else
   {
/*¸Elegxos an o arithmos twn thesewn einai sumvatos me th diata3h tou lewforeiou*/
      if ((theseis-5) > 0)                              //Afairw tis 5 theseis tis galarias
      {
         if ((theseis-5)%4 == 0)                        //An to upoloipo tis diairesis tou (sunolikou arithmou thesewn- tis 5 theseis tis galarias)
         {                                             // me to 4 dld mia 4ada ana seira einai mhden tote oles oi seires einai 4ades
/*Ektupwsh kuriws menu programmatos*/
             printf ("\n****************************************************************************");
             printf ("\n1. Emfanhsh synolikwn kenwn thesewn kai toy arithmoy toys\n");
             printf ("\n2. Krathsh theshs me sygkekrimeno arithmo.\n");
             printf ("\n3. Eyresh kai krathsh ths prwths kenhs theshs poy vrisketai se parathyro.\n");
             printf ("\n4. Akyrwsh krathshs theshs me sygkekrimeno arithmo.\n");
             printf ("\n5. Anazhthsh gia to an einai krathmenh thesh me sygkekrimeno arithmo.\n");
             printf ("\n6. Emfanhsh listas krathmenwn thesewn taksinomhmenhs kata arithmo theshs.\n");
             printf ("\n7. Emfanhsh pinakidas kykloforias kai toy diagrammatos toy lewforeioy.\n");
             printf ("\n8. Apothhkeysh pinakidas kykloforias kai toy diagrammatos toy lewforeioy.\n");
             printf ("\n0. Termatismos programmatos.");
             printf ("\n****************************************************************************\n");
/*¸Elegxos epiloghs xrhsth*/
             do
             {
               printf ("\n\nParakalw eisagete ton arithmo ths antistoixhs epiloghs sas apo to parapanw menu.");
               scanf("%d", &selection);
               if (selection >= 0 && selection <=8)
               {
/*Epilogh 1*/
                  if (selection == 1)
                  {
	                 countEmpty=0;

    			     for (i=0; i<theseis; i++)
                     {
                         if (bus[i]==0)
                            countEmpty++;
                     }
                     printf ("\nO arithmos twn kenwn thesewn toy lewforeioy einai: %d", countEmpty);
                     printf ("\nOi kenes theseis toy lewforeioy einai:\n");
                     for (i=0; i<theseis; i++)
                     {
                         if (bus[i]==0)
                         {
                            emptySeats=i+1;
                            printf ("%d ",emptySeats);
                         }
                     }
				  }
/*Epilogh 2*/
                  else if (selection == 2)
                  {
                     printf ("\nParakalw eisagete ton arithmo ths theshs poy thelete na krathsete.\n");
                     flag=0;
                     do
                     {
                       scanf("%d", &selSeat);
                       if (selSeat>0 && selSeat<=theseis)                       //Elegxos oti i thesi einai entos oriwn
                       {
                         if (bus[selSeat-1]==0)                               //Elegxos oti den einai kratimeni
                         {
                            bus[selSeat-1]=1;
                            printf ("H krathsh pragmatopoihthhke me epityxia.\n");
                            flag=1;
                         }
                         else
                            printf ("H sygkekrimenh thesh den einai diathesimh. Parakalw dokimaste ksana.\n");
                       }
                       else
                       {
                          printf ("Eisagate mh egkyrh timh. Parakalw dokimaste ksana.\n");
                       }
                     }while (flag==0);                                          //An to flag ginei 1 termatizei tin epanalipsi k sunexizei to programma

                  }
/*Epilogh 3*/
                  else if (selection == 3)                              //Analutikh epe3hghsh tou erwthmatos sto arxeio epe3hghseis askhsewn
                  {
                     i=0;
                     flag=0;
                     while (i<theseis && flag==0)                       //Elegxos entos oriwn twn thesewn tou lewforeiou
                     {
                        if (theseis-i>5)                                //E3etazetai to kuriws swma tou lewforeiou plhn galarias
                        {
                           if (bus[i]==0)
                           {
                              bus[i]=1;
                              printf ("H krathsh pragmatopoihthhke me epityxia.Kraththhke h thesh No%d\n",i+1);
                              flag=1;
                           }
                           else
                           {
                              if (i%2==1)                           //An einai perittos vrisketai sth de3ia pleura tou lewforeiou
                                 i++;                               //ara h epomenh thesh einai k auth parathyro giauto to i au3anetai kata 1
                              else                                  //An einai artios vrisketai sthn aristerh pleura tou lewforeiou
                                 i=i+3;                             //ara h epomenh thesh parathyro einai meta apo 3 theseis giauto to i au3anetai kata 3
                           }
                        }
                        else                                    //Edw e3etazetai h periptwsh ths galarias
                        {
                           if (bus[i]==0)
                           {
                              bus[i]=1;
                              printf ("H krathsh pragmatopoihthhke me epityxia.Kraththhke h thesh No%d\n",i-1);
                              flag=1;
                           }
                           else                                 //To i au3anetai kata 4 dioti h galaria exei 5 theseis
                              i=i+4;                            //apo to ena parathyro mexri to allo akriano parathyro einai 4 theseis
                        }
                     }
                     if (flag==0)
                       {
                           printf ("Den yparxoyn theseis parathyroy.\n");
                       }
                  }
/*Epilogh 4*/
                  else if(selection == 4)
                  {
                     printf ("\nParakalw eisagete ton arithmo ths theshs poy thelete na akyrwsete.\n");
                     flag=0;
                     do
                     {
                       scanf("%d", &deselSeat);
                       if (deselSeat>0 && deselSeat<=theseis)       //Elegxos oti o arithos einai entos oriwn
                       {
                         if (bus[deselSeat-1]==1)                 //Elegxos oti einai krathmenh
                         {
                            bus[deselSeat-1]=0;
                            printf ("H akyrwsh krathshs pragmatopoihthhke me epityxia.\n");
                            flag=1;
                         }
                         else
                            printf ("H sygkekrimenh thesh den einai krathmenh. Parakalw dokimaste ksana.\n");       //Periptwsh mh krathmenhs theshs k epanalhpsh diadikasias
                       }
                       else
                       {
                          printf ("Eisagate mh egkyrh timh. Parakalw dokimaste ksana.\n");                      //Periptwsh mh egkyrhs timhs theshs k epanalhpsh diadikasias
                       }
                     }while (flag==0);
                  }
/*Epilogh 5*/
                  else if (selection == 5)
                  {
                     printf ("\nParakalw eisagete ton arithmo ths theshs poy thelete na anazhthsete.\n");
                     flag=0;
                     do
                     {
                       scanf("%d", &searchSeat);
                       if (searchSeat>0 && searchSeat<=theseis)             //Elegxos oti o arithos einai entos oriwn
                       {
                         if (bus[searchSeat-1]==0)
                            printf ("H sygkekrimenh thesh einai kenh.\n");
                         else
                            printf ("H sygkekrimenh thesh einai krathmenh.\n");
                         flag=1;
                       }
                       else
                       {
                          printf ("Eisagate mh egkyrh timh. Parakalw dokimaste ksana.\n");      //Periptwsh mh egkyrhs timhs theshs k epanalhpsh diadikasias
                       }
                     }while (flag==0);
                  }
/*Epilogh 6*/
                  else if (selection == 6)
                  {
                     printf ("\nOi krathmenes theseis tou lewforeiou einai:\n");
                     for (i=0; i<theseis; i++)
                     {
                         if (bus[i]==1)                           //Elegxos an h thesh einai krathmenh kai ektypwsh ths
                         {
                            reservedSeats=i+1;
                            printf ("%d ", reservedSeats);
                         }
                     }
                  }
/*Epilogh 7*/
                  else if (selection == 7)
                  {
                     printf ("\n");
                     for (i=0; i<7; i++)
                     {
                         printf("%c",plateNum[i]);
                     }
                     printf ("\n");
                     corridorNum=theseis/4-1;               //Ypologizei poses 4ades exoume
                     line=1;                                //Arxikopoihsh metavlhtwn
                     seatNum=0;
                     while (seatNum<theseis)
                     {
                         if (line <= corridorNum)                   //E3etazoume prwta tis 4ades
                         {
                            for (j=0; j<5; j++)
                            {
                               if (j!=2)                            //Epeidi o pinakas metraei apo to 0 sth thesh 2 thelw na exei diadromo
                               {                                    //giauto vazw keno na ektypwnei
                                  if (bus[seatNum]==0)
                                     {                              //Ekei pou vriskei 0 tha to kanei - diladi kenh thesh
                                         printf ("_");
                                     }
                                  else
                                     {
                                        printf ("*");               //Ekei pou de tha vrei 0 tha to kanei * diladi krathmenh thesh
                                     }
                               seatNum++;
                               }
                               else
                                   printf (" ");                    //Ektypwnei to keno diladi thn apeikonhsh tou diadromou tou lewforeiou
                            }
                         }
                         else                                       //Edw tha e3etasei th galaria pou exei 5 theseis
                         {
                            for (k=0; k<5; k++)
                            {
                                if (bus[seatNum]==0)
                                   printf ("_");
                                else
                                   printf ("*");

                                seatNum++;
                             }
                         }
                         line++;                                    //Au3anei to line gia na paei sthn epomenh 4ada
                         printf ("\n\n");
                     }
                  }
/*Epilogh 8*/
                  else if (selection == 8)
                  {
                       FILE *f;
		               f =fopen("layout.txt", "w");                 //Dimiourgei arxeio txt opou mporei na grapsei kai to
                                                                    //apothhkeuei me onoma layout
		               if (!f)
                       {
                          printf("\nAdynamia anoigmatos arxeioy\n");
                          exit;
                       }
                       else
                       {                                               //H idia diadikasia me to erwthma 7 alla edw to typwnei sto txt
                           for (i=0; i<7; i++)
                           {
                               fprintf(f,"%c",plateNum[i]);
                           }
                           fprintf (f,"\n");
                           corridorNum=theseis/4-1;
                           line=1;
                           seatNum=0;
                           while (seatNum<theseis)
                           {
                              if (line <= corridorNum)
                              {
                                 for (j=0; j<5; j++)
                                 {
                                     if (j!=2)
                                     {
                                        if (bus[seatNum]==0)
                                           fprintf (f,"_");
                                        else
                                           fprintf (f,"*");
                                        seatNum++;
                                     }
                                     else
                                         fprintf (f," ");
                                 }
                              }
                              else
                              {
                                  for (k=0; k<5; k++)
                                  {
                                      if (bus[seatNum]==0)
                                         fprintf (f,"_");
                                      else
                                          fprintf (f,"*");

                                      seatNum++;
                                   }
                               }
                               line++;
                               fprintf (f,"\n\n");
                           }
                           fclose(f);
                       }
                       printf("To arxeio sas apothikeuthike me epitixia me onoma layout.txt");

                  }
/*Epilogh 0*/
                  else
                  {
                      printf ("\nTermatismos programmatos.\n");
                      exit;
                  }
               }
               else
               {
                  printf ("\nEisagate mh egkyrh timh. Parakalw dokimaste ksana.\n");
               }

             }while (selection != 0);
         }
/*Periptwsh pou oi theseis einai <53 alla de symvadizoun me th diata3h tou lewforeiou*/
         else
         {
             printf ("\nO arithmos twn thesewn toy lewforeioy den symvadizei me thn epitrepth katanomh.\n");
             exit;
         }
/*Periptwsh pou oi theseis einai <5 opote kai pali de symvadizoun me th diata3h tou lewforeiou*/
      }
      else
      {
          printf ("\nO arithmos twn thesewn toy lewforeioy den symvadizei me thn epitrepth katanomh.\n");
          exit;
      }
   }
   fclose(pToFile);
   printf ("\n\n");
   system("pause");
}
