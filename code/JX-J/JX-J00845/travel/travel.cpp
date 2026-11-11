#include <bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string c1,s1,c2,s2,a,b;
    cin>>c1>>s1>>c2>>s2;
    a=s1[0]+s1[1];
    b=s2[0]+s2[1];
    if(c1==c2){
        if(a==b){
            if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='A'&&s2[2]=='C')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='F'&&s2[2]=='D')){
                if((s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')||(s1[2]=='D'&&s2[2]=='F')||(s1[2]=='B'&&s2[2]=='A')||(s1[2]=='C'&&s2[2]=='B')||(s1[2]=='F'&&s2[2]=='D')){
                    cout<<1111;
                    return 0;
                }
                else{
                    cout<<1110;
                    return 0;
                }

            }
            else{
                cout<<1100;
                return 0;
            }

        }
        else{
            cout<<1000;
            return 0;
        }
    }
    else{
        cout<<0<<0<<0<<0;
        return 0;
    }
    return 0;
}
