#include <bits/stdc++.h>
#pragma GCC optimize("O2")
#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#define int long long
using namespace std;
int c,T,n,d,i,j,ans,a[2000010];
bool judge(int x,int y){
	while(x<=y){
		int t=x+1;
		while(a[t]-a[x]<=d&&t<=y) t++;
		if(t==y+1) return 0;
		x=t+1;
	}
	return 1;
}
main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>d;ans=0;
		for(i=1;i<=n;i++) cin>>a[i];
		for(i=1;i<n;i++)
			for(j=i+1;j<=n;j++)
				if(judge(i,j)) ans++;
		cout<<ans<<"\n";
	}
	return 0;
}
