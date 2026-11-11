#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
void solve(){
	int n;
	cin>>n;
	vector<pair<int,char>> a(n+1);
	ll len=0;
	for(int i=1;i<=n;i++){
		cin>>a[i].first>>a[i].second;
//		len+=a[i].first;
	}
	int l=1,r=n;
	ll last=0;
	char la;
	ll ans=0;
	while(l<=r){
		if(last>0){
			if(last>=a[l].first){
				last-=a[l].first;
				if(la!=a[l].second)
					ans+=a[l].first;
				l++;
				continue;
			}
			else{
				a[l].first-=last;
				if(la!=a[l].second)
					ans+=last;
			}
		}
		while(a[l].first>0&&l<r){
			if(a[l].second!=a[r].second)
				ans+=min(a[l].first,a[r].first);
			a[l].first-=a[r].first;
//			sum2+=a[r].first;
			r--;
		}
		last=-1*a[l].first;
		la=a[r+1].second;
		l++;
	}
//	if(ans>len/2)
//		ans=len/2;
	cout<<ans;
	return ;
}
int main(){
	fast;
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
