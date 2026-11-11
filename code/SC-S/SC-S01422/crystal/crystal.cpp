#include<bits/stdc++.h>
using namespace std;
#define ll  long long
const ll nn=5e5+5;
ll n,m,a[nn],b[nn],maxn=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(ll i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(ll i=2;i<=n;i++){
		ll x=a[i]-a[i-1];
		b[i]=b[i-1]+(i-1)*x;
	}
	for(ll i=1,j=1,sum=0;i<=n&&j<=n;i++){
		if(j<i)j=i;
		sum=b[j]-b[i];		
		while(j<=n&&sum<=m){
			maxn=max(maxn,j-i+1);
			if(j==n) break;
			j++;
			sum=b[j]-b[i];
		}
	}
	cout<<maxn;
	return 0;
}//long long