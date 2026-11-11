#include<bits/stdc++.h>
using namespace std;
int n,m;
string a,b;
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>n>>a>>m>>b;
    if(n==m){
        cout<<"1";
        if(a[0]==b[0]&&a[1]==b[1]){
            cout<<"1";
            if(a[2]<='C'&&b[2]<='C'||a[2]>='D'&&b[2]>='D'){
                cout<<"1";
                if(abs(a[2]-b[2])==1){
                    cout<<"1";
                }else{
                    cout<<"0";
                }
            }else{
                cout<<"00";
            }
        }else{
            cout<<"000";
        }
    }
    return 0;
}
