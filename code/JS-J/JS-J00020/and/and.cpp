#include<bits/stdc++.h>
using namespace std;
const int maxq=1e5+10;
int v[maxq],f[maxq];
int n,l,ans;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    int n,W;cin>>n>>W;
    for(int i=1;i<=n;i++){
        cin>>v[i];
        l=max(l,v[i]);
    }
    int ll=v[1];
    f[1]=l;
    for(int i=1;i<n;i++){
        for(int j=i+1;j<=n;j++){
            ans=max(ans,(v[i]&v[j]));
        }
    }
    f[2]=ans;
    for(int i=1;i<=n;i++){
        for(int j=W;j>=3;j--){
            int k=f[j-1];
            int u=(k&v[i]);
            f[j]=max(f[j],u);
            //cout<<j<<" "<<f[j]<<endl;
        }
    }
    if(W==n){
        for(int i=2;i<=n;i++)ll&=v[i];
        cout<<ll;
        return 0;
    }
    cout<<f[W];
    return 0;
}
