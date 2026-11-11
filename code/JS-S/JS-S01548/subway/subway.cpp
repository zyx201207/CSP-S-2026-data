#include<bits/stdc++.h>
using namespace std;
struct stu{
    int sta;
    long long t;
};
stu s0;
const long long INF = 1e18;
long long w[500005];
vector<int> lt[505];
vector<stu> st_su[500005];
long long di[505][505];
int c,n,m,d,q,k;
int a1,t1;
void solve(){
    for(int i = 1;i<=n;i++){
        cin>>k;
        for(int j = 0;j<k;j++){
            cin>>a1>>t1;
            s0.sta = i;
            s0.t = t1;
            st_su[a1].push_back(s0);
        }
    }
    for(int i = 1;i<=n;i++){
        for(int j = 1;j<=n;j++){
            di[i][j] = INF;
        }
    }
    queue<int>u;
    queue<int>v;
    for(int i  = 1;i<=m;i++){
        for(stu j:st_su[i]){
            int j1 = j.sta;
            for(stu k:st_su[i]){
                int k1 = k.sta;
                if(j1 <= k1)continue;
                if(di[j1][k1]==INF){
                    lt[j1].push_back(k1);
                    lt[k1].push_back(j1);
                }
                int md = min(j.t+k.t,di[j1][k1]);
                di[j1][k1] = md;
                di[k1][j1] = md;
                u.push(j1);
                v.push(k1);
            }
        }
    }while(!u.empty()){
        int u1 = u.front(),v1 = v.front();
        u.pop();
        v.pop();
        int w1 = di[u1][v1];
        for(int i:lt[u1]){
            if(di[v1][i]>w1+di[u1][i]){
                if(di[v1][i] == INF){
                    lt[v1].push_back(i);
                    lt[i].push_back(v1);
                }
                di[v1][i]=w1+di[u1][i];
                di[i][v1]=w1+di[u1][i];
            }
        }
        for(int i:lt[v1]){
            if(di[u1][i]>w1+di[v1][i]){
                if(di[u1][i] == INF){
                    lt[u1].push_back(i);
                    lt[i].push_back(u1);
                }
                di[u1][i]=w1+di[v1][i];
                di[i][u1]=w1+di[v1][i];
            }
        }
    }
    long long ans = INF;
    while(q--){
        int s,e;
        cin>>s>>e;
        for(stu j:st_su[s]){
            for(stu k:st_su[e]){
                ans = min(ans,j.t+k.t+di[j.sta][k.sta]);
            }
        }cout<<ans+w[s]+w[e]<<endl;
        ans = INF;
    }
    return;
}
int main(){
    freopen("subway.in","r",stdin);
    freopen("subway.out","w",stdout);

    cin>>c>>n>>m>>d>>q;
    for(int i = 1;i<=m;i++){
        cin>>w[i];
    }
    solve();
    return 0;
}
