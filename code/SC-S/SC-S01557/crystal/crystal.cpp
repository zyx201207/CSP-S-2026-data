#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	ll n,m;
	cin>>n>>m;
	vector<ll> a;
	a.resize(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	sort(a.begin(),a.end());
	ll ans,lst_ans=-1LL>>1,used;
	for(int i=0;i<n;i++){
		ans=1,used=0;
		for(int j=i-1;j>=0;j--){
			used+=a[i]-a[j];
			if(used<=m) ans++;
		}
		if(ans<lst_ans) break;
		lst_ans=ans;
	}
	cout<<lst_ans<<'\n';
	return 0;
}