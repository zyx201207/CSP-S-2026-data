#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
const int N=2e5+5;
struct BIT{
    int cn,num,cn1;
    bool bit[31];
    void init(int _n){
        for(int i=0;i<31;i++){
            bit[i]=0;
        }
        cn=0;
        num=_n;
    }
};
BIT a[N];
void solve(){
    int n,m;
    cin>>n>>m;
    int mx=-1e18,mxcn=0;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        int cn=0;
        a[i].init(x);
        while(x){
            a[i].bit[cn++]=(x%2);
            x/=2;
        }
        for(int j=0;j<31;j++){
            a[i].cn1+=a[i].bit[j];
        }
        if(mxcn<a[i].cn1){
            if(mx<a[i].num)
                mx=a[i].num,mxcn=a[i].cn1;
        }
    }
    BIT maxn;
    int cnt=0;
    maxn.init(mx);
    maxn.cn1=mxcn;
    while(mx){
        maxn.bit[cnt++]=(mx%2);
        mx/=2;
    }
    vector<int>v;
    for(int i=0;i<31;i++){
        if(maxn.bit[i]==1){
            v.push_back(i);
        }
    }
    for(int i=1;i<=n;i++){
        for(int it:v){
            if(a[i].bit[it]==1){
                a[i].cn++;
            }
        }
    }
    sort(a+1,a+1+n,[&](BIT x,BIT y){
        if(x.cn==y.cn)return x.num>y.num;
        return x.cn>y.cn;
    });
    int ans=a[1].num;
    for(int i=2;i<=m;i++){
        ans&=a[i].num;
    }
    cout<<ans<<endl;
}
signed main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
    //cin>>t;
    while(t--){
        solve();
    }
    return 0;
}