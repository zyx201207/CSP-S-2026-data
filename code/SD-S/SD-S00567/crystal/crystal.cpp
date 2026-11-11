#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],maxx=1,c[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		c[i]=a[i]-a[i-1];
	}
	c[1]=0;
	ll l=1,r=1,sum=0,len=1;
	while(l<=r&&r<=n){
		r++;
		if(r>n){
			break;
		}
		len=r-l+1;
		sum+=(len-1)*c[r];
		if(sum<=m){
			maxx=max(maxx,len);
		}
		else{
			while(sum>m){
				sum-=(a[r]-a[l]);
				l++;
			}
			len=r-l+1;
		}
	}
	cout<<maxx;
	return 0;
}

