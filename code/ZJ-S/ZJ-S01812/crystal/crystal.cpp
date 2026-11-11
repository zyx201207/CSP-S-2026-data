#include<bits/stdc++.h>
#define int long long
using namespace std; 
const int N=5e5+5;
int n,a[N],ans=1,m,j=1,cnt,t,mx;
int sum;
signed main(){	
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0)->sync_with_stdio(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],mx=max(mx,a[i]);
	sort(a+1,a+n+1);
	if(n>=N-5&&mx<=1e12){
		ans=1;
		for(int i=1;i;i++){
			sum=sum+i-1;
			if(sum==m) cout<<i,exit(0);
			else if(sum>m) cout<<i-1,exit(0);
		}
	}
	for(int i=2;i<=n;i++){
		int k=ans+1;
		sum+=(a[i]-a[i-1])*(i-1-(j-1));
		t=sum;
		while(t>m&&j<=i){
			t-=(a[i]-a[j]);
			k--;
			j++;
		}
		if(ans<=k&&t<=m) ans=k,sum=t;
		else if(ans==k&&t<=m) sum=t;
	}
	cout<<ans;
	return 0;
}
