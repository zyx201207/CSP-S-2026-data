#include<bits/stdc++.h>
using namespace std;
string c1,s1,c1,s2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin >>c1>>s1>>c2>>s2;
    if(c1==c2)
    {
        cout <<1;
        for(int i=0;i<1;i++){
            if(s1[i!=s2[i]) f=0;
        }
        if(f!=1)cout <<000;
        else{
            cout <<1;
            if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F'))
            {
                cout <<1;
            }
            else if((s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='F'&&s2[2]=='D'))
            {
                cout <<1;
            }
            else{
                cout <<0;
                f=0;
            }
        }
        if(f==1)
        {
            cout <<1;
        }
        else cout <<0;
    }
    else cout<<0000;
}
