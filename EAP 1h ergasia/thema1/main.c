#include <stdio.h>

int main()
{float num1,num2,sum,s,m,d;                                             //Dhlwsh metavlhtwn
char pr;

    printf("Dwse arithmo pra3i arithmo\n");                             //Ektypwsh mhnumatos
    scanf("%f %c %f",&num1,&pr,&num2);                                  //Plhktrologhsh apo ton xrhsth arithmou-pra3hs-arithmou
    sum=num1+num2;                                                      //Oi pra3eis pou 8a ektelounte analoga me th periptwsh
    s=num1-num2;
    m=num1*num2;
    d=num1/num2;
    //Periptwsh prostheshs
    if (pr=='+')
    {
        printf("apotelesma = %.2f\n",sum);
    }
    //Periptwsh afaireshs
    else if (pr=='-')
    {
        printf("apotelesma = %.2f\n",s);
    }
    //Periptwsh pollaplasiasmou
    else if (pr=='*')
    {
        printf("apotelesma = %.2f\n",m);
    }
    //Periptwsh diaireshs
    else if (pr=='/')
    {

        if (num2==0)                                                                //Periptwsh adynaths diaireshs me to 0
        {
            printf("H diairesh me to 0 einai adynath, o 2os arithmos de prepei na einai 0\n");
        }
        else
         {
             printf("apotelesma = %.2f\n",d);                                       //Ektypwsh apotelesmatos
         }

    }
    else                                                                            //Periptwsh pou o xrhsths dwsei pra3h diaforetikh apo "+,-,*,/"
    {
        printf("Dwse swsth pra3h\n",&s);
    }
return 0;
}

