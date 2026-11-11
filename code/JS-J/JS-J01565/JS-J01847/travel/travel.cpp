#include<bits/stdc++.h>
using namespace std;
int a,b,x,y;
char c1,c2;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c1>>x>>y>>c2;
    if(a!=x){
        cout<<"0000";
    }else{
        cout<<"1";
        if(b!=y){
            cout<<"000";
        }else{
            cout<<"1";
            if((c1=='D'&&c2=='E')||(c1=='E'&&c2=='D')){
                cout<<"11";
            }else if(c1!='D'&&c1!='E'&&c2!='D'&&c2!='E'){
                cout<<"1";
                if(abs(c1-c2)==1) cout<<"1";
                else cout<<"0";
            }else{
                cout<<"00";
            }
        }
    }
    return 0;
}
