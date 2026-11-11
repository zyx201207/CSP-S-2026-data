#include <bits/stdc++.h>
using namespace std;
int n,m;
int a[500010];
bool b[500010],c[500010];
int ans[500010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=n;i>=1;i--){
        if(b[a[i]]){
            c[i]=1;
            for(int j=i+1;j<=n && a[j]!=a[i];j++) c[j]=1;
        }
        b[a[i]]=1;
        for(int j=n;j>=i;j--) if(c[j]==0) ans[a[j]]++;
    }
    for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
    return 0;
}
