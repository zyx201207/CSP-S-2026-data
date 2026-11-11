#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef __int128 lll;
map<ll,ll>mp;
ll n,m;
vector<ll> a;
int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k;
        a.push_back(k);
        mp[k]++;
    }
    sort(a.begin(),a.end());
    a.erase(unique(a.begin(),a.end()),a.end());
    ll maxn=0;
    for(int i=a.size();i>=0;i--){
        ll sum=mp[a[i]],mm=m,k=1;
        while(mm&&k<=i){
            if(mm>=mp[a[i-k]]*(a[i]-a[i-k])){
                mm-=mp[a[i-k]]*(a[i]-a[i-k]);
                sum+=mp[a[i-k]];
            }else{
                sum+=mm/(a[i]-a[i-k]);
                mm=0;
            }
            k++;
        }
        maxn=max(maxn,sum);
    }
    cout<<maxn<<endl;
    return 0;
}
