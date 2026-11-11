#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
ll a[500005];
ll suf[500005];
ll sufcnt[500005];
vector<ll> b;
unordered_map<ll,int> ump;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
     freopen("crystal.in","r",stdin);
     freopen("crystal.out","w",stdout);
    cin>>n>>m;
    for(int i=0;i<n;i++){
        cin>>a[i];
        ump[a[i]]++;
    }
    sort(a,a+n);
    for(int i=n-1;i>=0;i--) suf[i]=suf[i+1]+a[i];
    for(int i=0;i<n;i++) b.push_back(a[i]);
    b.erase(unique(b.begin(),b.end()),b.end());
    for(int i=b.size()-1;i>=0;i--) sufcnt[i]=sufcnt[i+1]+ump[b[i]];
    long long ans=0;
    for(int i=0;i<b.size();i++){
        int l=0,r=n-sufcnt[i];
        while(l<r){
            int mid=(l+r)/2;
            if(b[i]*(n-sufcnt[i]-mid)-(suf[mid]-suf[n-sufcnt[i]])<=m) r=mid;
            else l=mid+1;
        }
        ans=max(ans,ump[b[i]]+n-sufcnt[i]-l);
    }
    cout<<ans;
    return 0;
}