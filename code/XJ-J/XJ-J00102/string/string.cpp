#include <bits/stdc++.h>
using ll=long long;
using namespace std;
struct Group{
    int len;
    char c;
};
constexpr int MAXN=200005;
Group groups[MAXN];
int main(){
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    ll n,L=0,p=0;
    cin>>n;
    vector<ll> arr;
    for(int i=0;i<n;i++){
        cin>>groups[i].len>>groups[i].c;
        arr.push_back(p);
        p+=groups[i].len;
    }
    arr.push_back(p);
    L=p,p=0;
    for(int i=n-1;i>=0;i--){
        arr.push_back(p);
        p+=groups[i].len;
    }
    arr.push_back(p);
    sort(arr.begin(),arr.end());
    arr.erase(unique(arr.begin(),arr.end()),arr.end());
    ll l=0,pl=groups[l].len,r=n-1,pr=groups[r].len;
    ll res=0;
    for(ll i=0;l<=r&&arr[i]<=L>>1;i++){
        if(arr[i]>=pl) pl+=groups[++l].len;
        if(arr[i]>=pr) pr+=groups[--r].len;
        if(groups[l].c!=groups[r].c){
            res+=min(arr[i+1],L>>1)-arr[i];
        }
    }
    cout<<res<<'\n';
    return 0;
}