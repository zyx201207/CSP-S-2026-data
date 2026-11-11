#include<bits/stdc++.h>
using namespace std;
const int maxq=6e5+10;
int a[maxq],w[maxq],f[maxq],ll[maxq];
int ap;
int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    memset(ll,0,sizeof(ll));
    int n,m;cin>>n>>m;
    for(int i=1;i<=n;i++)cin>>a[i];
    for(int i=1;i<=n;i++){
        memset(f,0,sizeof(f));
        memset(w,0,sizeof(w));
        int we=i;
        for(int j=i;j<=n;j++){
            if(w[a[j]]==0)w[a[j]]=we;
            else{
                for(int k=w[a[j]];k<we;k++)f[k]=0;
                we=w[a[j]];
            }
            f[we]=a[j];
            we++;
        }
        for(int s=i;s<=n;s++)ll[f[s]]++;
    }
    for(int i=1;i<=m;i++)cout<<ll[i]<<" ";
    return 0;
}
