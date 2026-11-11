#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll cnt[500010];
ll a[500010];
ll k[500010];
ll n,m,len=1;
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
            memset(k,-1,sizeof(k));
            len=1;
        for(int j=i;j<=n;j++){
            bool f=0;
            for(int l=1;l<=len;l++){
                if(k[l]==a[j]){
                    for(int u=l;u<=len;u++){
                        k[u]=-1;
                    }f=1;
                    len=l;
                }if(f)break;
            }k[len]=a[j];
            len++;
        }for(int j=1;j<=len-1;j++)cnt[k[j]]++;
    }for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
    return 0;
}
