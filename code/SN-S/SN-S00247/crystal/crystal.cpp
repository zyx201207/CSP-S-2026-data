#include <bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[512345],lol[512345];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out ","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	lol[1]=0;
	for(int i=2;i<=n;i++){
		lol[i]=lol[i-1]+(a[i]-a[i-1]);
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		int cnt=0;
		for(int j=1;j<=i;j++){
			cnt+=lol[i]-lol[j];
		}
		if(cnt<=m){
			ans=max(i,ans);
		}
	}
	cout<<ans;
}
