#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void ouverture();
void head();
void body(char address);
void fermeture();
char get_class();

int main()
{
    char address;
    ouverture();
    head();
    address=get_class();
    body(address);
    fermeture();
}

char get_class()
{
    char ip[100];
    int cas0,cas1,cas2,cas3,i;
    strcpy(ip,getenv("QUERY_STRING"));
    if(strlen(ip)<5)
    {
        return (1);
    }
    if(strstr(ip,"IP="))
    {
        if(sscanf(ip,"IP=%d.%d.%d.%d",&cas0,&cas1,&cas2,&cas3)==4)
        {
            if( cas0<0||cas0>255 )
                return(0);
            if( cas1<0||cas1>255 )
                return(0);
            if( cas2<0||cas2>255 )
                return(0);
            if( cas3<0||cas3>255 )
                return(0);

            if(cas0>=0 && cas0<=127)
                return('A');
            else if(cas0>=128 && cas0<=191)
                return('B');
            else if(cas0>=192 && cas0<=223)
                return('C');
            else if(cas0>=224 && cas0<=239)
                return('D');
            else if(cas0>=240 && cas0<=255)
                return('E');
        }
        else{
            return(0);
        }
    }
    return(1);
}

void ouverture()
{
    printf("Content-type: text/html\n\n");
    printf("<html>");
}

void head()
{
    printf("    <head>");
    printf("        <title>Address IP</title>");
    printf("        <style>");
    printf("body{\
            padding-top:100px;\
            background-color: black;\
            color: white;\
            font-size:30px;\
            }");
    printf(" h,#address,#ip{"
            "background-color: grey;\
            padding:10px;\
            text-align: center;\
            width:300px;\
            color:#efe;\
            border-radius: 10px;\
            animation-name: circle;\
            animation-duration: 3s;\
            animation-timing-function: none;\
            animation-delay: 0s;\
            animation-iteration-count: infinite;\
            animation-direction: alternate;"
            "}");
    printf("@keyframes circle{\
            100%%{background-color: grey;color:white;}\
            0%%{background-color:#222;color:white;}\
            }");
    printf("form{\
            font-size:25px;\
            border:4px solid #555;\
            background-color: #333;\
            padding: 1%%;\
            margin-top: 0px;\
            width:40%%;\
            border-radius:10px;\
        }");
    printf("input,select{\
            font-size:20px;\
            padding-left: 20px;\
            width:94%%;\
            height:30px;\
            border-radius:5px;\
            border:none;\
            background-color:#DDD;\
        }");
    printf("#link{\
            height:40px;\
            border-color:white;\
            width: 90%%;\
            border-radius:10px;\
            background-color: #0B0;\
            color:white;\
            }   \
            #link:hover{\
                background-color: #090;");  
    printf("        </style>");
    printf("    </head>");
}   

void body(char address)
{
    char ip[100];
    strcpy(ip,getenv("QUERY_STRING"));
    ip[2]=':';
    printf("    <body>");
    printf("        <center>");
    printf("        <h>Recherche de Classe d'addresse IP</h>");
    printf("            <br>");
    printf("            <br>");
    printf("        <form act&ion=""IP.cgi"" method=""get"" >");
    printf("            Entrer l'addresse IP-v4:");
    printf("            <br>");
    printf("            <br>");
    printf("            <input type=""texte"" name=""IP"" placeholder="" Addresse-IP"" >");
    printf("            <br>");
    printf("            <br>");
    printf("            <input type=""submit"" id=""link"" value=""Recherche"">");
    printf("            <br>");
    printf("            <br>");
    printf("        </form>");
    if(address == 0 )
        printf("            <p>Addresse IP incorrect</p>");
    if(address ==1)
        printf("            <p>Address manquante</p>");
    if(address=='A'  || address=='B' ||address=='C'||address=='D' ||address=='E')
    {
        printf("            <p id=""ip"">%s</p>",ip);
        printf("            <p id=""address"">Classe %c</p>",address);
    }
    printf("        </center>");
    printf("    </body>");
}

void fermeture()
{
    printf("</html>");
}