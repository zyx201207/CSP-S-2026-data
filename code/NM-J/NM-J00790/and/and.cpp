#include<bits/stdc++.h>
using namespace std;
int n,m,q[200000],t;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);

    cin>>n>>m;
    for(int i=1;i<=n;i++){
            cin>>q[i];
        }
    if(m==n){
        for(int i=1;i<=n;i++){
            t=t&q[i];
        }
    }
    if(m==1){for(int i=1;i<=n;i++){
            t=max(t,q[i]);
        }}

cout<<t;
    return 0;
}
