#include<bits/stdc++.h>
using namespace std;
#define int long long 
using ii=__int128;
constexpr int maxn=5e5+10;
inline int read(){
    int f=0,num=0,c=cin.rdbuf()->sbumpc();
    while(!isdigit(c)){
        if(c=='-')f=1;
        c=cin.rdbuf()->sbumpc();
    }
    while(isdigit(c)){
        num=(num<<1)+(num<<3)+(c^48);
        c=cin.rdbuf()->sbumpc();
    }
    return f?-num:num;
}
mt19937 rd(random_device{}());
signed main(){
    // freopen("migrate.in","r",stdin);
    freopen("migrate0.in","w",stdout);
    ios::sync_with_stdio(0),cin.tie(0);
    // int c=read(),t=read();
    cout<<"0 1\n";
    int n=300,d=rd()%40000;
    cout<<n<<" "<<d<<"\n";
    unordered_set<int>vis;
    vector<int>a;
    int o=rd()%40000;
    a.emplace_back(o);
    for(int i=2;i<=n;++i){
        while(1){
            int p=rd()%d+1;
            if(rd()&1){
                p=-p;
            }
            int u=o+p;
            if(vis.count(u))continue;
            vis.emplace(u);
            a.emplace_back(u);
            break;
        }
    }
    sort(a.begin(),a.end());
    for(int v:a){
        cout<<v<<" ";
    }
    return 0;
}