#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005];
vector<pair<int,int>>edge[500005],change[500005];
vector<long long>anss;
void read(int k,int note){
    int u1,u2,u3,v;
    if(k<=3){
        cin>>u1>>v;
        change[u1].emplace_back(note,v);
        cin>>u2>>v;
        change[u2].emplace_back(note,v);
        edge[u1].emplace_back(note,u2);
        edge[u2].emplace_back(note,u1);
        cin>>u3>>v;
        change[u3].emplace_back(note,v);
        edge[u3].emplace_back(note,u2);
        edge[u2].emplace_back(note,u3);
        return;
    }
    cin>>u1>>v;
    change[u1].emplace_back(note,v);
    for(int i=2;i<=k;i++){
        if(i%3==2){
            cin>>u2>>v;
            change[u2].emplace_back(note,v);
            edge[u1].emplace_back(note,u2);
            edge[u2].emplace_back(note,u1);
            continue;
        }
        if(i%3==0){
            cin>>u3>>v;
            change[u3].emplace_back(note,v);
            edge[u3].emplace_back(note,u2);
            edge[u2].emplace_back(note,u3);
            continue;
        }
        if(i%3==1){
            cin>>u1>>v;
            change[u1].emplace_back(note,v);
            edge[u1].emplace_back(note,u3);
            edge[u3].emplace_back(note,u1);
            continue;
        }
    }
}
long long QwQ(int x,int y){
    long long ans=0;
    queue<pair<int,int>>q;
    ans+=w[x];
    anss[x]=0;
    int j=0,minn=0x7fffffff,mins;
    for(pair<int,int>i:change[x]){
        j++;
        if(minn>i.second){
            minn=i.second;
            mins=change[x][j].first;
        }
    }
    ans+=minn;
    q.push({x,minn});
    while(!q.empty()){
        pair<int,int>f=q.front();
        anss[f.first]=ans-w[x];
        q.pop();
        ans+=f.second;
        j=0,minn=0x7fffffff;
        for(pair<int,int>i:change[f.first]){
            j++;
            if(minn>i.second){
                minn=i.second;
                mins=change[f.first][j].first;
            }
        }
        for(pair<int,int>i:edge[f.first]){
            if(anss[f.first]+f.second<anss[i.second])
                q.push({i.second,minn});
        }
    }
    return ans;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++)
        cin>>w[i];
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        read(k,i);
    }
    anss.resize(m);
    while(q--){
        fill(anss.begin(),anss.end(),0x7fffffff);
        int x,y;
        cin>>x>>y;
        cout<<QwQ(x,y)<<'\n';
    }
    return 0;
}