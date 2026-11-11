#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,c2,s1,s2;
    char a,b;
    cin>>c1>>s1>>a>>c2>>s2>>b;
    if(c1==c2){
        cout<<1;
        if(s1==s2){
            cout<<1;
            if((a=='A' and (b=='B' or b=='C')) or (a=='B' and (b=='A' or b=='C')) or (a=='C' and (b=='B' or b=='A')) or (a=='F' and b=='D') or (a=='D' and b=='F')){
                cout<<1;
                if((a=='A' and b=='B') or (a=='B' and (b=='A' or b=='C')) or (a=='C' and b=='B') or (a=='D' and b=='F') or (a=='F' and b=='D')){
                    cout<<1;
                }
                else{
                    cout<<0;
                }
            }
            else{
                cout<<0<<0;
            }
        }
        else{
            cout<<0<<0<<0;
        }
    }
    else{
        cout<<0<<0<<0<<0;
    }
    return 0;
}
//you's 1 like l
//if hall(diyu)
