#include<bits/stdc++.h>
using namespace std;
#define maxn 2000010
using ll=long long;

int n,c,t;
ll d;
ll pos[maxn];

ll s1_cnt,s1_len;
void dfs(int u,ll dep,int ed){
    if(u==ed){
        if(dep<s1_len){
            s1_cnt=1;
            s1_len=dep;
        }
        else if(dep==s1_len)s1_cnt++;
        return;
    }
    for(int i=u+1;i<=ed;i++){
        if(pos[i]-pos[u]>d)break;
        dfs(i,dep+1,ed);
    }
}

void solv1(){
    ll ans=0;
    for(int i=1;i<=n-1;i++){
        for(int j=i+1;j<=n;j++){
            s1_cnt=0,s1_len=50;
            dfs(i,1,j);
            if(s1_cnt==2)ans++;
        }
    }
    cout<<ans<<endl;
}


int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++){
            cin>>pos[i];
        }
        if(n<=9){
            solv1();
            continue;
        }
    }

    return 0;
}
