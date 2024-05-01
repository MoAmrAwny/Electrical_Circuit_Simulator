#include<iostream>
#include<string>
#include<cmath>
using namespace std;
double series(string x)
{
  int n= x.length();
  float b=0,Req=0;
  string a="";
  for(int i=2; i <= (n-2) ; i++)
  {
    if (x[i]==' ')
     {
      float b = stof(a);
      Req = Req + b;
      a="";
     }
    else if ( x[i]!='S' && x[i]!='P' && int(x[i])>= 65 && x[i]!= 'e' )
    {
       cout<<"wrong circuit description\n";
       break;
    }
    else a= a+ x[i];
 }
  return Req;
}


double parallel(string x)
{
  int n= x.length();
  float b=0,Req=0,R2=0;
  string a="";
  for(int i=2; i <= (n-2) ; i++)
  {
    if (x[i]==' ' )
     {
      float b = stof(a);
      R2=R2 +(1/b);
      Req= pow(R2,-1);
      a="";
     }
    else if ( x[i]!='S' && x[i]!='P' && int(x[i])>= 65 && x[i]!= 'e' )
    {
       cout<<"wrong circuit description\n";
       break;
    }
    else a= a+x[i];
 }
  return Req;
}



