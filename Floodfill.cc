void FloodFill()
{
int i,j; //Definir variables locales para esta función
inicializa_cola();
//Inicializar valores de las celdas
for(i=0;i<Orden_L;i++)
for(j=0;j<Orden_L;j++)
{
celda[i][j].valor=255;
celda[i][j].calculado=false;
celda[i][j].en_cola=false;
}
//Comienza la inundación dando el valor de cero a la solución
if(!regreso)
if(Orden_L%2==1) //En caso de que el orden del laberinto sea impar (una celda de solución)
{
celda[SolR][SolC].valor=0;
celda[SolR][SolC].calculado=true;
celda[SolR][SolC].en_cola=true;
almacena(SolR,SolC);
}
else //En caso de que el orden del laberinto sea par (4 celdas de solución)
{
celda[SolR][SolC].valor=0;
celda[SolR][SolC].calculado=true;
celda[SolR][SolC].en_cola=true;
almacena(SolR,SolC);
celda[SolR][SolC2].valor=0;
celda[SolR][SolC2].calculado=true;
celda[SolR][SolC2].en_cola=true;
almacena(SolR,SolC2);
celda[SolR2][SolC].valor=0;
celda[SolR2][SolC].calculado=true;
celda[SolR2][SolC].en_cola=true;
almacena(SolR2,SolC);
celda[SolR2][SolC2].valor=0;
celda[SolR2][SolC2].calculado=true;
celda[SolR2][SolC2].en_cola=true;
almacena(SolR2,SolC2);
}
else
{
celda[Ren0][Col0].valor=0;
celda[Ren0][Col0].calculado=true;
celda[Ren0][Col0].en_cola=true;
almacena(Ren0,Col0);
}
//Inunda las celdas adyacentes
while(recupera()!=NULL)
{
Indice[0]=cola[recover-1][0]; //Renglón
Indice[1]=cola[recover-1][1]; //Columna
CalculaAdyacentes(Indice[0],Indice[1],celda[Indice[0]][Indice[1]].muros);
}
return;
}