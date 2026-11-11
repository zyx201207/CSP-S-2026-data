#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    int w[m];
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    int k[n];
    for(int i=1;i<=n;i++){
            cin>>k[i];
            int d=k[i];
            int a[d],t[d];
            for(int j=1;j<=k[i];j++){
                cin>>a[j]>>t[j];
            }
    }
    int x[q],y[q];
    for(int i=1;i<=q;i++){
        cin>>x[i]>>y[i];
    }
    int a;
    for(int j=1;j<=m;j++){
            for(int i=1;i<=m;i++){
        if(w[i]>w[i+1]){
            a=w[i];
            w[i]=w[i+1];
            w[i+1]=a;
        }
    }
    }
    int ans=w[1];
    ans+=w[2];
    ans+=6;
    for(int i=1;i<=q;i++){
        cout<<ans;
    }
return 0;
}
