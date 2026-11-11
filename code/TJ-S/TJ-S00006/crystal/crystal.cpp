#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int maxn=5e5+10;
ll a[maxn],n,m,d[maxn],sd[maxn],j=1,ans;
ll sum=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		d[i]=a[i]-a[i-1];
	}
	for(ll i=1;i<=n;i++){
		sd[i]=d[i-1]+d[i];
	}
//	for(int i=1;i<=n;i++) cout<<d[i]<<' ';
//	cout<<endl;
//	for(int i=1;i<=n;i++) cout<<sd[i]<<' ';
//	cout<<endl;
	for(ll i=1;i<=n;i++){
		sum+=(i-j)*d[i];
		while(sum>m) sum-=(j-i)*(sd[i]-sd[j-1]),j++;
		ans=max(i-j+1,ans);
//		cout<<j<<' '<<sum<<' ';
	}
//	cout<<endl;
	cout<<ans;
	
	
	
	
	return 0;
}
