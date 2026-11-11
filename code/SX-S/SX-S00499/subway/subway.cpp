#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],k[505],lst;
vector<pair<int,int> > sb[505],bs[500005];
int dis[500005];
priority_queue<int> qu;
void dijk(int st){
    memset(dis,0x3f,sizeof(dis));
    dis[st]=0;
    qu.push(st);
    while(!qu.empty()){
        int pos=qu.top();
        qu.pop();
        if(lst==pos) continue;
        lst=pos;
        int t=dis[pos];
        for(pair<int,int> rut:bs[pos]){
            t+=rut.second;
            for(pair<int,int> uu:sb[rut.first]){
                if(dis[uu.first]>t+uu.second){
                    dis[uu.first]=t+uu.second;
                    qu.push(uu.first);
                }
            }
            t-=rut.second;
        }
    }
}
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        cin>>k[i];
        for(int j=1;j<=k[i];j++){
            int x,y;
            cin>>x>>y;
            sb[i].push_back({x,y});
            bs[x].push_back({i,y});
        }
    }
    while(q--){
        int x,y;
        cin>>x>>y;
        dijk(x);
        cout<<dis[y]+w[x]+w[y]<<endl;
    }
    return 0;
}
unsigned long long rp=-1;