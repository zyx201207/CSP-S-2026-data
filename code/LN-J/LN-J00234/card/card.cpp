#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],p[500005],w;
int s[300005],v[500005];
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
    }
    for(int i=1;i<=n;i++){
        memset(v,-1,sizeof(v));
        w=1;
        for(int j=i;j<=n;j++){
            if(v[a[j]]==-1){
                v[a[j]]=w;
                p[w]=a[j];
                w++;
            }else{
                w=v[a[j]]+1;
            }
        }
        memset(v,-1,sizeof(v));
        for(int j=1;j<w;j++){
            v[p[j]]=1;
        }
        for(int j=1;j<=m;j++){
            if(v[j]==1)s[j]++;
        }
    }
    for(int i=1;i<=m;i++){
        cout<<s[i]<<' ';
    }
    return 0;
}
