#include<bits/stdc++.h>
using namespace std;
const int N=500005,M=505;
const long long inf=4e18;
long long w[N],t[N],d[M][M];
int h[N],to[N],ne[N],id[N],n,m,q,tot;
int main(){
    freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
    int c,lim;
    cin>>c>>n>>m>>lim>>q;
    for(int i=1;i<=m;i++)cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1,x;j<=k;j++){
            long long y;
            cin>>x>>y;
            ++tot;
            to[tot]=i;
            t[tot]=y;
            ne[tot]=h[x];
            h[x]=tot;
            id[tot]=x;
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            d[i][j]=inf;
        }
        d[i][i]=0;
    }
    for(int i=1;i<=m;i++){
        int a[25],b[25],k=0;
        for(int j=h[i];j;j=ne[j]){
            a[++k]=to[j];
            b[k]=t[j];
        }
        for(int j=1;j<=k;j++){
            for(int x=j+1;x<=k;x++){
                long long v=b[j]+b[x];
                d[a[j]][a[x]]=min(d[a[j]][a[x]],v);
                d[a[x]][a[j]]=min(d[a[x]][a[j]],v);
            }
        }
    }
    for(int k=1;k<=n;k++){
        for(int i=1;i<=n;i++){
            if(d[i][k]==inf)continue;
            for(int j=1;j<=n;j++){
                if(d[k][j]==inf)continue;
                d[i][j]=min(d[i][j],d[i][k]+d[k][j]);
            }
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        long long ans=inf;
        for(int i=h[x];i;i=ne[i]){
            for(int j=h[y];j;j=ne[j]){
                ans=min(ans,t[i]+d[to[i]][to[j]]+t[j]);
            }
        }
        if(ans==inf)cout<<-1<<endl;//msly 
        else cout<<ans+w[x]+w[y]<<endl;
    }
    return 0;
}

