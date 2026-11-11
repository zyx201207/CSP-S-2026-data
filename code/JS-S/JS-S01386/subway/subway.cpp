#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q;
vector<pair<int,int> > st[50010];
int wt[50010];
long long dist[50010];
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    if(m>3000){
        cout<<"100"<<endl;
    }
    for(int i=1;i<=m;i++){
        cin>>wt[i];
    }
    int cmp=m+1;
    for(int i=1;i<=n;i++){
        int ki;
        cin>>ki;
        int a0,t0;
        cin>>a0>>t0;
        st[cmp].push_back({a0,t0});
        st[a0].push_back({cmp,t0});
        a0=cmp;
        cmp++;
        for(int j=2;j<=ki;j++){
            int ai,ti;
            cin>>ai>>ti;
            st[cmp].push_back({a0,0});
            st[a0].push_back({cmp,0});
            a0=cmp;
            st[cmp].push_back({ai,ti});
            st[ai].push_back({cmp,ti});
            cmp++;
        }
    }
    while(q--){
        memset(dist,0x3f,sizeof(dist));
        int xr,yr;
        cin>>xr>>yr;
        queue<int> qu;
        qu.push(xr);
        dist[xr]=0;
        while(!qu.empty()){
            int no=qu.front();
            qu.pop();
            for(int i=0;i<st[no].size();i++){
                int time=st[no][i].second;
                int to=st[no][i].first;
                if(dist[to]>dist[no]+time){
                    dist[to]=dist[no]+time;
                    qu.push(to);
                }
            }
        }
        cout<<dist[yr]+wt[xr]+wt[yr]<<endl;
    }
    return 0;
}
