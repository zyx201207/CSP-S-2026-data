#include <bits/stdc++.h>
using namespace std;
int c1,c2;
int s1,s2;
char a,b;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    scanf("%d %d%c %d %d%c",&c1,&s1,&a,&c2,&s2,&b);
    //cout<<c1<<s1<<a<<c2<<s2<<b;
    if(c1==c2){
        cout<<1;
        if(s1==s2){
            cout<<1;
            if((a<='C'&&b<='C')||(a>'C'&&b>'C')){
                cout<<1;
                if(abs(a-b)==1){
                    cout<<1;
                }else{
                    cout<<0;
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
