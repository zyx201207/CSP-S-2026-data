#include<bits/stdc++.h>
#define ll long long

using namespace std;
ll n,a[200010],sum,c[200010],V,m;
int mp[200010];
int lv;
int main(){
    freopen("and.in","r",stdin);
    freopen("and.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        V=max(V,a[i]);
        mp[i]=1;
    }
    lv=log2(V);
    for(int j=lv;j>=0;j--){
        ll cnt=0;
        for(int i=1;i<=n;i++)c[i]=(a[i]>>j)&1;
        for(int i=1;i<=n;i++)if(mp[i])cnt+=c[i];
        if(cnt>=m){
            sum+=(1<<j);
            for(int i=1;i<=n;i++)if(mp[i]&&!c[i])mp[i]=0;
        }
    }
    cout<<sum;
    return 0;
}
