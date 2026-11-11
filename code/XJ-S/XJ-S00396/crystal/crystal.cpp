#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500010],s[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m,d=0;
	cin>>n>>m;
	bool f=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i==1)continue;
		if(i>2&&d!=a[i]-a[i-1])f=0;
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		if(i>2&&d!=a[i]-a[i-1])f=0;
	}
	if(f){
		m*=2;
		int i=0;
		while(++i){
			if(i*(i+1)>m){
				cout<<i;
				return 0;
			}
		}
	}
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=i;j++){
			int x=s[i]-s[j-1];
			int y=i-j+1;
			if(y*a[i]-x<=m){
				ans=max(ans,y);
			}
		}
	}
	cout<<ans;
	return 0;
} 
