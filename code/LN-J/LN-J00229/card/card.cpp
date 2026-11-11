#include<bits/stdc++.h>
using namespace std;
int a[500005];
int cnt[300005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n,m;
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        int b[500005]={0};
        bool z[300005]={0};
        for(int j=i;j<=n;j++){
            if(z[a[j]]==1){
                int ii;
                for(ii=j-1;a[ii]!=a[j];ii--){
                    z[b[ii]]=0;
                    b[ii]=0;
                }
                b[ii-1]=0;
            }
            b[j]=a[j];
            z[b[j]]=1;
        }
        for(int j=1;j<=m;j++){
            if(z[j])cnt[j]++;
        }
    }
    for(int i=1;i<=m;i++)cout<<cnt[i]<<" ";
    return 0;
}
