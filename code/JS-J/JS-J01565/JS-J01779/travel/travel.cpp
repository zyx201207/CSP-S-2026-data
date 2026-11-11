#include<bits/stdc++.h>
using namespace std;
string x,x2,y,y2;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>x>>x2>>y>>y2;
    if(x!=y){
        cout<<"0000";
    }else{
        cout<<1;
        char c1=x2[0],c2=x2[1],d1=y2[0],d2=y2[1];
        if(c1!=d1||c2!=d2){
            cout<<"000";
        }else{
            cout<<1;
            int a=x2[2]-'A',b=y2[2]-'A';
            if(a<=2&&b<=2){
                cout<<1;
                if(abs(a-b)!=1){
                    cout<<0;
                }else{
                    cout<<1;
                }
            }else if(a>2&&b>2){
                cout<<"11"; 
            }else{
                cout<<"00";
            }
        }
    }
    return 0;
}