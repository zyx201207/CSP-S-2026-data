#include<bits/stdc++.h>
using namespace std;
const int mx=2e5+5;
int n,m,a[mx],ans;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	if(m==1){
		cout<<a[n];
		return 0;
	}
	if(m==n){
		ans=a[1];
		for(int i=2;i<=n;i++)ans=(ans&a[i]);
		cout<<ans;
		return 0;
	}
	if(m==2&&n<=10000){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				if(i!=j)ans=max(ans,a[i]&a[j]);
		cout<<ans;
		return 0;
	}
	if(m==n-1&&n<=10000){
		for(int i=1;i<=n;i++){
			int s=a[1];
			if(i==1)s=a[2];
			for(int j=1;j<=n;j++)
				if(i!=j)s=(s&a[j]);	
			ans=max(ans,s);
		}
		cout<<ans;
		return 0;
	}
	if(a[n]<=4){
		int aa,b;aa=b=0;
		for(int i=1;i<=n;i++)
			if(a[i]==4)aa++;
			else if(a[i]==2)b++;
		if(aa>=m){
			cout<<4;
			return 0;
		}
		if(aa+b>=m){
			cout<<2;
			return 0;
		}
		if(n-aa-b>=m){
			cout<<1;
			return 0;
		}
		cout<<0;
		return 0;
	}
	ans=a[n];
	for(int i=n-1;i>=n-m+1;i--)ans=(ans&a[i]);
	cout<<ans;
	return 0;
}
