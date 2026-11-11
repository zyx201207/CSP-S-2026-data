#include<bits/stdc++.h>
using namespace std;
long long c,n,m,d,q,g,ans;
long long a[500005];
long long f[500005][505];
vector<long long> s[500005];
long long line[1000][1000];
int main(){
    freopen("./subway.in","r",stdin);
    freopen("./subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(long long i=1;i<=m;i++){
        cin>>a[i];
    }
    for(long long i=1;i<=n;i++){
        cin>>g;
        while(g--){
            long long x,y;
            cin>>x>>y;
            f[x][i]=y;
            s[x].push_back(i);
        }
    }
    for(long long i=1;i<=n;i++){
        for(long long j=1;j<=n;j++){
            line[i][j]=0x3f3f3f3f3f3f3f3f;
        }
    }
    for(long long i=1;i<=n;i++)line[i][i]=0;
    for(long long i=1;i<=m;i++){
        for(long long j=0;j<s[i].size();j++){
            long long u=s[i][j];
            for(long long k=0;k<s[i].size();k++){
                long long v=s[i][k];
                if(u==v)continue;
                if(line[u][v]>f[i][u]+f[i][v]){
                    line[u][v]=f[i][u]+f[i][v];
                    line[v][u]=f[i][u]+f[i][v];
                }
            }
        }
    }
    for(long long k=1;k<=n;k++){
        for(long long i=1;i<=n;i++){
            for(long long j=1;j<=n;j++){
                if(line[i][k]+line[k][j]<line[i][j]){
                    line[i][j]=line[i][k]+line[k][j];
                    line[j][i]=line[i][k]+line[k][j];
                }
            }
        }
    }
    while(q--){
        long long x,y;
        cin>>x>>y;
        bool p=0;
        long long ans3=LONG_LONG_MAX,ans4=LONG_LONG_MAX;
        for(long long i=0;i<s[x].size();i++){
            for(long long j=0;j<s[y].size();j++){
                long long u=s[x][i];
                long long v=s[y][j];
                if(u==v){
                    p=1;
                    ans4=min(ans4,f[y][v]+f[x][v]);
                }
                ans3=min(ans3,line[u][v]+f[y][v]+f[x][u]);
            }
        }
        if(p==0)cout<<ans3+a[x]+a[y]<<"\n";
        else cout<<a[x]+a[y]+ans4<<"\n";
    }
    return 0;
}
//God,please help me!!!!!!!!!
//fake
// duck track pack fun to rhyme
// trick stick pick dinner time
// luogu id:kkksc03
