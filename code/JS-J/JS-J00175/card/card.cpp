#include<bits/stdc++.h>
using namespace std;
int n,m,a[200005],ans[100005];
bool c[505],v[205];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    if(n>500){
        for(int i=1;i<=n;i++){
            if(a[i+1]!=a[i])ans[i]=max(ans[a[i]],i);
        }
        for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
        return 0;
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++)c[j]=1;
        for(int j=1;j<=m;j++)v[j]=0;
        for(int j=i;j<=n;j++){
            for(int k=j-1;k>=i;k--){
                if(c[k]&&a[k]==a[j]){
                    while(k<j){
                        c[k]=0;
                        k++;
                    }
                    break;
                }
            }
        }
        for(int j=i;j<=n;j++){
            if(c[j]&&!v[a[j]]){
                ans[a[j]]++;
                v[a[j]]=1;
            }
        }
    }
    for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
    return 0;
}
