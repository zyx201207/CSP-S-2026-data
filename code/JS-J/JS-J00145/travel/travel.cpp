#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    string s1,s2,c1,c2;
    cin>>s1>>s2>>c1>>c2;
    if(s1==c1){
        cout<<1;
        if(s2[0]==c2[0]&&s2[1]==c2[1]){
            cout<<1;
            if((s2[2]-'A'<=2&&c2[2]-'A'<=2)||(s2[2]-'A'>2&&c2[2]-'A'>2)){
                cout<<1;
                if(s2[2]-c2[2]==1||s2[2]-c2[2]==-1){
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
