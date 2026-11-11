#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int c1,s1,c2,s2;
    char x1,x2;
    cin>>c1>>s1>>x1>>c2>>s2>>x2;
    if(c1==c2){
        cout<<1;
        if(s1==s2){
            cout<<1;
            if((x1=='A'||x1=='B'||x1=='C')&&(x2=='A'||x2=='B'||x2=='C')||(x1=='D'||x1=='F')&&(x2=='D'||x2=='F')){
                cout<<1;
                if(x1-'A'<=2&&x2-'A'<=2){
                    if(abs(x1-x2)==1){
                        cout<<1;
                    }else{
                        cout<<"0";
                        return 0;
                    }
                }else{
                    cout<<1;
                }
            }else{
                cout<<"00";
                return 0;
            }
        }else{
            cout<<"000";
            return 0;
        }
    }else{
        cout<<"0000";
        return 0;
    }
    return 0;
}
