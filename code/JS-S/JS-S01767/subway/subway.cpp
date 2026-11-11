#include<bits/stdc++.h>
using namespace std;
#define int long long
int w[500005],p[505][505];
vector<pair<int,int>>G[505],a[500005];
struct PQ {
    vector<pair<int,int>>v;
    int len=0;
    void up(int id){
        if(v[id]<v[(id-1)/2]){
            swap(v[id],v[(id-1)/2]);
            up((id-1)/2);
        }
        else{
            return;
        }
    }
    void down(int id){
        if(id*2+2>len){
            if(id*2+1<=len&&v[id*2+1]<v[id]){
                swap(v[id*2+1],v[id]);
            }
            return ;
        }
        if(v[id]>v[id*2+2]||v[id]>v[id*2+1]){
            if(v[id*2+2]<v[id*2+1]){
                swap(v[id*2+2],v[id]);
                down(id*2+2);
            }
            else{
                swap(v[id*2+1],v[id]);
                down(id*2+1);               
            }
        }
        else{
            return ;
        }
    }
    pair<int,int>top(){
        return v[0];
    }
    void push(pair<int,int> u){
        len++;
        if(v.size()<len){
            v.push_back({0,0});
        }
        v[len-1]=u;
        up(len-1);
    }
    void pop(){
        len--;
        swap(v[0],v[len]);
        down(0);
    }
};
signed main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);
    int c,n,m,d,q;
    cin>>c>>n>>m>>d>>q;
    for(int i=1;i<=m;i++){
        cin>>w[i];
    }
    for(int i=1;i<=n;i++){
        signed k;
        cin>>k;
        for(int j=1;j<=k;j++){
            int u,v;
            cin>>u>>v;
            a[u].push_back({i,v});
        }
    }
    for(int i=1;i<=m;i++){
        for(int j=1;j<a[i].size();j++){
            for(int k=0;k<j;k++){
                int u1=a[i][j].first,v1=a[i][j].second,u2=a[i][k].first,v2=a[i][k].second;
                G[u1].push_back({u2,v1+v2});
                G[u2].push_back({u1,v1+v2});
            }
        }
    }
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            p[i][j]=LLONG_MAX;
            p[j][j]=0;
        }
        PQ Q;
        Q.push({0,i});
        while(Q.len){
            auto t=Q.top();
            int d=t.first,u=t.second;
            Q.pop();
            for(auto e:G[u]){
                int w1=e.second,v=e.first;
                if(d+w1<p[i][v]){
                    Q.push({d+w1,v});
                    p[i][v]=d+w1;
                }
            }
        }
    }
    while(q--){
        int u,v;
        cin>>u>>v;
        int ans=LLONG_MAX;
        for(auto e1:a[u]){
            for(auto e2:a[v]){
                int l1=e1.first,k1=e1.second,l2=e2.first,k2=e2.second;
                int cost=k1+k2+p[l1][l2];
                ans=min(ans,cost);
            }
        }
        cout<<w[u]+w[v]+ans<<"\n";        
    }
    return 0;
}