#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5e5+5;
ll n,m,ans,lst[N],sm[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>lst[i];
	sort(lst+1,lst+n+1);
	for(ll i=1;i<=n;i++) sm[i]=sm[i-1]+lst[i];
	ll l=1,r=1;
	while(r<=n && l<=n && l<=r){
        if(lst[r]*(r-l+1)-sm[r]+sm[l-1]<=m){
            ans=max(ans,r-l+1);
            r++;
        }else{
            l++;
        }
	}
	cout<<ans;
	return 0;
}
