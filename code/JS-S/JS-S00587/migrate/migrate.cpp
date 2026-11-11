#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int c,t;
ll n,d;
ll a[50000];
vector<ll> v;
inline void dfs(int l,int r,ll sum){
    if(l==r){
        if(sum==0)
            return ;
        v.push_back(sum);
        return ;
    }
    for(int i=l+1;i<=r;i++){
        if(abs(a[i]-a[l])<=d){
            dfs(i,r,sum+1);
        }
    }
}
inline bool check(int l,int r){
    v.clear();
    dfs(l,r,0);
    sort(v.begin(),v.end());
    if(!v.empty()&&v[0]==v[1]&&v[1]!=v[2]){
        // cout<<l<<" "<<r<<'\n';
        // for(int i=0;i<v.size();i++){
        //     cout<<v[i]<<'\n';
        // }
        return true;
    }
    return false;
}
int main(){
    freopen("migrate.in","r",stdin);
    freopen("migrate.out","w",stdout);
    cin>>c>>t;
    while(t--){
        cin>>n>>d;
        for(int i=1;i<=n;i++)
            cin>>a[i];
        ll cnt=0;
        for(int i=1;i<=n-3;i++){
            for(int j=i+3;j<=n;j++){
                if(check(i,j))
                    cnt++;
            }
        }cout<<cnt<<'\n';
    }
    return 0;
}//dui pai T1!!!!!!!!!!!!!!!!!!!!!!!
// g++ migrate.cpp -o migrate -std=c++14 -O2