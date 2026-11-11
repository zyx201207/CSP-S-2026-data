#include<bits/stdc++.h>
using namespace std;
int n;
pair<long long,char> p[200005];
long long l,r;
long long ans;
int main(){
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    freopen("string.in","r",stdin);
    freopen("string.out","w",stdout);
    cin>>n;
    for(int i=0;i<n;i++) cin>>p[i].first>>p[i].second;
    l=0,r=n-1;
    while(l<r){
        long long k=min(p[l].first,p[r].first);
        if(p[l].second!=p[r].second) ans+=k;
        p[l].first-=k;
        p[r].first-=k;
        if(p[l].first<=0) l++;
        if(p[r].first<=0) r--;
    }
    cout<<ans;
    return 0;
}