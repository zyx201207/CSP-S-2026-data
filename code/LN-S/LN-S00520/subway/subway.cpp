#include<bits/stdc++.h>
using namespace std;
int n,m,w[1001],c,q,d,ti[1001][1001];
set<int>tag[1001],tab[1001];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        scanf("%d",&w[i]);
    }
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int x,t;
            scanf("%d%d",&x,&t);
            tab[j].insert(x);
            tag[x].insert(j);
            ti[k][x]=t;
        }
    }
    while(q--){
        int s,e,ans=w[s]+w[e],tmp=0;
        scanf("%d%d",&s,&e);
        if(tab[1].find(s)==tab[1].end()) ans+=ti[2][s];
        else ans+=ti[1][s];
        if(n==2){
            for(int i=1;i<=m;i++) if(tag[i].size()>0) tmp=min(tmp,ti[1][i]+ti[2][i]+ti[2][e]);
            ans+=tmp;
        }
        cout<<ans<<'\n';
    }
    return 0;
}