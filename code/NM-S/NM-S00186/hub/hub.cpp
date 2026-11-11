#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[10000001],v[100000001];
int main(){
    freopen("hub.in","r",stdin);
    freopen("hub.out","w",stdout);
    cin>>c>>t;
    for(int i=1;i<=t;i++){
        cin>>n>>k;
        for(int j=1;j<=n-1;j++){
            cin>>u[i]>>v[i];
        }
    }
    fclose(stdin);
    fclose(stdout);
    return 0;
}
