#include<bits/stdc++.h>
using namespace std;
int tg1,tg2,tg3,tg4;
bool zvp(string k,string l)
{
    if(k[1]+k[0]==l[1]+l[0])
    return true;
    return false;

}
bool zvc(string k,string l)
{

    if(k[2]=='A'||k[2]=='B'||k[2]=='C'){
         if(l[2]=='A'||l[2]=='B'||l[2]=='C')
            return true;
    }
    else{
         if(l[2]=='D'||l[2]=='E')
            return true;
    }


    return false;

}
bool zvl(string k,string l)
{

   if(k[2]=='A'&&l[2]=='C')
    return false;
  if(l[2]=='A'&&k[2]=='C')
    return false;


    return true;

}
int main(){
freopen("travel.in","r",stdin);
freopen("travel.out","w",stdout);

int n,n2;
string a,b;
cin>>n>>a>>n2>>b;
if(n==n2)
    tg1++;
else{
    cout<<"0000";
    return 0;
}
    cout<<tg1;
if(zvp(a,b))
    tg2++;
else{
    cout<<"000";
    return 0;
}
    cout<<tg2;
    if(zvc(a,b))
        tg3++;
else{
        cout<<"00";
    return 0;
}
    cout<<tg3;
 if(zvl(a,b))
        tg4++;
else{
        cout<<"0";
    return 0;
}
    cout<<tg4;
    return 0;
}
