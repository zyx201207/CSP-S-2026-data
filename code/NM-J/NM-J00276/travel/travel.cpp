#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    int a,b;
    string r,x;
    cin>>a>>r>>b>>x;
    if(a==b){
        cout<<1;
            if(r[0]==x[0]&&r[1]==x[1]){
            cout<<1;
            if(r[2]=='A'||r[2]=='B'||r[2]=='C'){
                if(x[2]=='A'||x[2]=='B'||x[2]=='C'){
                    cout<<1;
                    if((r[2]=='A'&&x[2]=='B')||(r[2]=='B'&&x[2]=='A')||(r[2]=='B'&&x[2]=='C')||(r[2]=='C'&&x[2]=='B')){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }else{
                    cout<<"00";
                }
            }
            if(r[2]=='D'||r[2]=='F'){
                if(x[2]=='D'||r[2]=='F'){
                    cout<<1;
                    if((r[2]=='D'&&x[2]=='F')||(r[2]=='F'&&x[2]=='D')){
                        cout<<1;
                    }else{
                        cout<<0;
                    }
                }else{
                    cout<<"00";
                }
            }
        }else{
            cout<<"000";
        }
    }else{
        cout<<"0000";
    }
    return 0;
}
