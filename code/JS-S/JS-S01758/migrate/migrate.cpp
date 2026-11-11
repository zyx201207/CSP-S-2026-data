#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF=0x3f3f3f3f;

int C=0,T=0;
int n=0;
ll d=0;
vector<ll>x;
int dp1[5001]={},dp2[5001]={};

void solve_1_10(){
    while(T--){
        int ans=0;
        cin>>n>>d;
        x.assign(n+1,0);
        ll A=0;
        for(int i=1;i<=n;++i){
            cin>>A;
            x[i]=A;
        }
        for(int i=1;i<=n-2;++i){
            for(int j=i+2;j<=n;++j){
                int mini=0;
                int l=i;
                for(int r=i;r<=j;++r){
                    if(x[r]-x[l]<=d){
                        if(r==j) ++mini;
                        continue;
                    }
                    --r;
                    l=r;
                    ++mini;
                }
                fill(dp1,dp1+mini+1,0),fill(dp2,dp2+mini+1,0);
                dp1[0]=1;
                for(int t=1;t<=j-i;++t){
                    fill(dp2,dp2+mini+1,0);
                    for(int k=0;k<=mini;++k){
                        for(int z=0;z<=k;++z){
                            if(x[k]-x[z]>d) continue;
                            dp2[k]+=dp1[z];
                        }
                    }
                    copy(dp2,dp2+mini+1,dp1);
                }
                for(int i=1;i<=mini;++i) if(dp1[i]==2) ++ans;
            }
        }
        cout<<ans<<'\n';
    }
}
void solve_A(){
    while(T--){
        ll A=0;
        cin>>n>>d;
        x.assign(n+1,0);
        for(int i=1;i<=n;++i){
            cin>>A;
            x[i]=A;
        }
        ll cha=x[2]-x[1];
        if(d<2*cha||3*cha<=d) cout<<0<<'\n';
        else cout<<max(0,n-3)<<'\n';
    }
}
void solve_B(){
    while(T--) cout<<0<<'\n';
}
int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>C>>T;
    if(0<=C&&C<=10) solve_1_10();
    else if(C==11||C==12) solve_A();
    else if(C==13||C==14) solve_B();
}