#define ll long long
#include<bits/stdc++.h>
using namespace std;
const int N=500010;

ll n,k;
ll a[N],c[N],s[N],ss[N];

void solve(){
    cin>>n>>k;
    map<ll,int>mp;
    vector<ll>v;
    for(int i=1;i<=n;i++) cin>>a[i],v.push_back(a[i]);
    sort(v.begin(),v.end()),v.erase(unique(v.begin(),v.end()),v.end());
    for(int i=0;i<v.size();i++) mp[v[i]]=i+1;
    for(int i=1;i<=n;i++) c[mp[a[i]]]++;
    s[1]=c[1],ss[1]=0;
    for(int i=2;i<=v.size();i++) ss[i]=ss[i-1]+s[i-1]*(v[i-1]-v[i-2]),s[i]=s[i-1]+c[i];
    ll ans=0;
    for(int i=1;i<=v.size();i++){
        int l=0,r=i;
        while(l+1<r){
            int m=l+(r-l+1)/2;
            if(ss[i]-ss[m]-(m>0?s[m-1]*(v[i-1]-v[m-1]):0)<=k) r=m;
            else l=m;
        }
        ll sy=k-(ss[i]-ss[r]-s[r-1]*(v[i-1]-v[r-1]));
        ans=max(ans,s[i]-s[r-1]+(r>1?sy/(v[i-1]-v[r-2]):0));
    }
    cout<<ans<<"\n";
}

int main(){
    freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
    ios::sync_with_stdio(0);
    cin.tie(0),cout.tie(0);
    int t=1;
//    cin>>t;
    while(t--) solve();
}
