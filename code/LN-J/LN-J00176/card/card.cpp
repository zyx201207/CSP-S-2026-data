#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],t[300010];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n>>m;
    for(long long i=1;i<=n;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        long long vis[300010]={0},tmp[300010]={0},b[500010],c=i;
        for(long long j=i;j<=n;j++){
            if(vis[a[j]]!=0){
                c=vis[a[j]];
                for(long long k=c;k<=j;k++) vis[a[k]]=0;
                tmp[c]=a[j];
            }
            else{
                vis[a[j]]=c;
                tmp[c]=a[j];
            }
            c++;
        }
        for(long long j=i;j<c;j++){
            t[tmp[i]]++;
        }
    }
    for(long long i=1;i<=m;i++){
        cout<<t[i]<<" ";
    }
    return 0;
}
