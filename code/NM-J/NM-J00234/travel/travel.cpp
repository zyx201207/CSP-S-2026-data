#include <bits/stdc++.h>
using namespace std;
int a,f;
char b,c,d,e,g,h,i,j;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("teavel.out","w",stdout);
    cin>>a>>b>>c>>d>>e>>f>>g>>h>>i>>j;

   if(a==f)
    {
        cout<<1;
    }

    else
    {
        cout<<"0000";
        return 0;
    }
    if(b==g&&c==h){
        cout<<1;

    }
    else{
       cout<<"000";
        return 0;
    }
    int zuo,yo,l;
    if((d=='A'||d=='B'||d=='C')&&(i=='A'||i=='B'||i=='C')){
        zuo=1;
    }
    if((d=='E'||d=='D')&&(i=='E'||i=='D')){
        yo=1;
    }


    if(zuo||yo){
    cout<<1;
    }
    else{
        cout<<"00";
        return 0;
    }
    if((d=='A'&&i=='B')||(d=='B'&&i=='C')||(d=='D'&&i=='F')||(i=='A'&&d=='B')||(i=='B'&&d=='C')||(i=='D'&&d=='F')){
        cout<<1;
    }
    else{
        cout<<0;
        return 0;
    }

    return 0;
}
