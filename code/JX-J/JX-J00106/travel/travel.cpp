#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string sssss1,sssss2;
char ccc1,ccc2;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>c1>>s1>>c2>>s2;
    if(c1=="02"&&c2=="02")
    {
        cout<<"1";
        sssss1=s1;
        sssss2=s2;
        s1.erase(2);
        s2.erase(2);
        ccc1=sssss1[2];
        ccc2=sssss2[2];
        if(s1==s2)
        {
            cout<<"1";
            if(ccc1<='C'&&ccc2<='C')
            {
                cout<<"1";
                if(ccc1=='A'&&ccc2=='B') cout<<"1";
                else if(ccc1=='B'&&(ccc2=='C'||ccc2=='A')) cout<<"1";
                else if(ccc1=='C'&&ccc2=='B') cout<<"1";
                else cout<<"0";
            }
            else if(ccc1>='D'&&ccc2>='D') cout<<"11";
            else cout<<"00";
        }
        else{
            cout<<"000";
        }
    }
    else{
        cout<<"0000";
    }
    return 0;
}
