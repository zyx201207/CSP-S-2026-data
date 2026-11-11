#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[300005];
ll ans[300005]={};
ll s[500005]={},k;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	bool yx=1;cin>>a[0];
	for(ll i=1;i<n;i++){
		cin>>a[i];
		if(a[i-1]>a[i]) yx=0;
	}
	if(yx){
		ans[a[n-1]]=1;
		for(ll i=n-2;i>=0;i--){
			for(ll j=m;j>=max(a[i]-1,0);j--) if(ans[j]) ans[j]++;
			if(a[i]!=a[i+1]) ans[a[i]]++;
		}
		for(ll i=1;i<=m;i++) cout<<ans[i]<<' ';
		return 0;
	}
	for(ll start=0;start<=n;start++){
		bool cot[300005]={};
		k=0;
		for(ll i=start;i<n;i++){
			bool de=cot[a[i]];
			if(de) while(s[k]!=a[i]) cot[s[k--]]=0;
			//if(de) cout<<i<<'\n';
			s[k++]=a[i];cot[a[i]]=1;
		}
		for(ll j=0;j<=m;j++) ans[j]+=cot[j];
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}

