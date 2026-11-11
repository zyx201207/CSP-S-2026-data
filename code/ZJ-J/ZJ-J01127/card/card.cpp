#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,a[500005],last[500005],q[500005],cnt[300005];
void solve(ll id){
	ll sum=0;
	for(ll i=id;i<=n;i++){
		if(last[a[i]]==0){
			q[++sum]=a[i];
			last[a[i]]=sum;
		}else{
			for(ll j=last[a[i]]+1;j<=sum;j++)last[q[j]]=0;
			sum=last[a[i]];
		}
	}
	for(ll i=1;i<=sum;i++)cnt[q[i]]++;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++)cin>>a[i];
	if(n<=500){
		for(ll i=1;i<=n;i++){
			memset(last,0,sizeof last);
			solve(i);
		}
		for(ll i=1;i<=m;i++)cout<<cnt[i]<<' ';
		return 0;
	}
	bool flag=1;
	for(ll i=1;i<n;i++){
		if(a[i]>a[i+1])flag=0;
	}
	if(flag==1){
		for(ll i=1;i<=n;i++)cnt[a[i]]=i;
		for(ll i=1;i<=m;i++)cout<<cnt[i]<<' ';
		return 0;
	}
	if(m==1){
		cout<<n;
		return 0;
	}
	if(m==2){
		ll s=0;
		if(a[n]==1){
			for(ll i=1;i<=n;i++)s+=(a[i]==2);
			cout<<n<<' '<<s;
		}else{
			for(ll i=1;i<=n;i++)s+=(a[i]==1);
			cout<<s<<' '<<n;
		}
	}
	return 0;
}
