#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2;
    cin>>c1>>s1>>c2>>s2;
    int y1=c1[1]-'0';
    int y2=c2[1]-'0';
    int y3=c1[0]-'0';
    int y4=c2[0]-'0';
    int z1=s1[2]-'A';
    int z2=s2[2]-'A';
    int z3=s1[0]-'A'+17;
    int z4=s1[1]-'A'+17;
    int z5=s2[0]-'A'+17;
    int z6=s2[1]-'A'+17;
    //cout<<z3<<endl<<z4<<endl<<z5<<endl<<z6;

    if(y1==y2&&y3==y4)
        cout<<"1";
    else
    {
       cout<<"0000";
        return 0;
    }
    if(z3==z5&&z4==z6)
        cout<<"1";
    else{
        cout<<"000";
        return 0;
    }
    if(abs(z1-z2)<=2&&(z1!=3&&z2!=3)&&(z1!=2&&z1!=1&&z2!=2&&z2!=1))
        cout<<"1";
    else
    {
        cout<<"00";
        return  0;
    }

    if(abs(z1-z2)==1)
        cout<<"1";
    else{
         cout<<"0";
         return 0;
    }

    return 0;
}
