#include<bits/stdc++.h>
using namespace std;
int c,n,m,d,q,w[500005],pl[2][100005],k[505],t[505][500005],vis[505];
long long ans=0x3f3f3f3f3f3f3f3f;
struct node{
    long long to,ln;
};
struct node2{
    long long nw,ln;
    bool operator <(const node2 A){
        return A.ln<ln;
    }
};
vector<node> e[505];
bool a[505][500005];
queue<node2> qu;
int main(){
    freopen("subway1.in","r",stdin);
    freopen("subway.out","w",stdout);
    cin>>c>>n>>m>>d>>q;
    for(int i=0;i<m;i++){
        cin>>w[i];
    }
    for(int i=0;i<n;i++){
        cin>>k[i];
        for(int j=0;j<k[i];j++){
            int u;
            cin>>u;
            cin>>t[i][u];
            for(int l=0;l<n;l++){
                if(a[l][u]){
                    e[i].push_back(node{l,t[l][u]+t[i][u]});
                    e[l].push_back(node{i,t[l][u]+t[i][u]});
                }
            }
            a[i][u]=1;
        }
    }
    for(int i=0;i<q;i++){
        cin>>pl[0][i]>>pl[1][i];
    }
    for(int i=0;i<q;i++){
        qu.push(node2{pl[0][i],w[pl[0][i]]+w[pl[1][i]]});
        while(!qu.empty()){
            node2 tmp=qu.front();
            qu.pop();
            if(tmp.nw==pl[1][i]){
                cout<<ans<<"\n";
            }
            for(auto i:e[tmp.nw]){
                qu.push(node2{i.to,i.ln+tmp.ln});
            }
        }
        while(!qu.empty()){
            qu.pop();
        }
    }
    return 0;
}
