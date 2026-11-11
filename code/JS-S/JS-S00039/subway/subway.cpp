#include<bits/stdc++.h>
using namespace std;
const int N=510,M=5e5+10,D=30;
int w[M],k[N],a[N][N],t[N][N],sch[N][D],cnt[D];
int st,ed,c,n,m,d,q;
int bfs(int aaa){
    for(int i=1;i<=k[aaa];i++){
        if(a[aaa][i]==ed)return t[aaa][ed];
    }
    int ansnxt=INT_MAX;
    for(int i=1;i<=k[aaa];i++){
        int tmp=t[aaa][i];
        for(int j=1;j<=cnt[a[aaa][i]];j++){
            tmp+=t[sch[a[aaa][i]][j]][a[aaa][i]];
            if(sch[a[aaa][i]][j]!=aaa){
                ansnxt=min(ansnxt,tmp+bfs(sch[a[aaa][i]][j]));
            }
        }
    }
    return ansnxt;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            cin>>a[i][j]>>t[i][j];
            sch[j][++cnt[j]]=i;
        }
    }
    if(n<=50){
        while(q--){
            cin>>st>>ed;
            int ans=w[st]+w[ed],bfsans=INT_MAX;
            for(int i=1;i<=cnt[st];i++)bfsans=min(bfsans,bfs(i)+t[i][st]);
            ans+=bfsans;
            cout<<ans<<'\n';
        }
    }
    return 0;
}
/*
LuoguUid==LSQ11451410086
*/
