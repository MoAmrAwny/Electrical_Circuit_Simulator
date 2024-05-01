#include<iostream>
#include<string>
#include<cmath>
using namespace std;
double series(string x);
double parallel(string x);

int main()
{
    int j=0;
    double EqRES=0,val1=0,val2=0, z=0,r=0,v=0;
    string inputs , L="",M=" " ;// M for main connection , L for internal connection.
    cout<<"please enter your circuit description ( type of connections followed 'e' to end each internal connection
    and 'E' to end the whole connection) : \n ";
    getline(cin,inputs);
    cout<<" Please enter the voltage: ";
    cin>>v;
    if(inputs[0]=='S')
    {
        for(int i = 2 ;i<inputs.length();i++)
        {
           if(inputs[i]=='S' || inputs[i]=='P')
           {
             for ( j=i; j < inputs.length(); j++)
             {
               L+= inputs[j];
               if(inputs[j]=='e')break;
             }
             i=j+1;
             if(L[0]=='S') val1+=series(L);
             if(L[0]=='P') val1+=parallel(L);
             L="";
           }
          else M+=inputs[i];
        }
        val2+= series(M);
        z= val1 + val2 ;
        EqRES=z;
        cout<<"The total resistance is : "<<EqRES<<" ohms"<<"\n";
        cout<< "The current is : "<< v / EqRES <<" ampere \n";
    }
    if(inputs[0]=='P')
    {
      for(int i = 2 ;i<inputs.length();i++)
      {
         if(inputs[i]=='S' || inputs[i]=='P')
         {
           for ( j=i; j < inputs.length(); j++)
           {
             L+= inputs[j];
             if(inputs[j]=='e')break;
           }
           i=j+1;
           if(L[0]=='S')
           {
           val1=series(L);
           r+=1/val1;
           }
           if(L[0]=='P')
           {
             r=parallel(L);
             val1+=1/r;
           }
           L="";
         }
        else M+=inputs[i];
      }
      if ( M==" E")z=r;
      else
        {
        val2+= parallel(M);
        z= (r) + (1/val2) ;
        }
      EqRES=pow(z,-1);
      cout<<"The total resistance is : "<<EqRES<<" ohms"<<"\n";
      cout<< "The current is : "<< v / EqRES<<" ampere \n";
    }
    if(inputs[0]!= 'S' && inputs[0]!='P' )
      {
       cout<<" Wrong circuit description \n";
      }
}
