#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int N=5e5+10;
ll n,m;
ll a[N],b[N],c[N];
ll ans;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=a[i]-a[i-1];
	}
	ll sum=0,l=1,c=0;
	for(int i=1;i<=n;i++){
		c+=b[i];
		sum+=(i-l+1)*b[i];
		while(sum>m){
			sum-=c;
			c-=b[l];
			l++;
		}
		if(sum<=m){
			ans=max(ans,i-l+1);
		}
	}
	cout<<ans+1<<'\n';
	
	return 0;
}