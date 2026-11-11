#include<bits/stdc++.h>
#define int long long
using namespace std;
int p[500005],ans=0,sum=0,n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	int a[n+1];
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	int cl=1,cr=1;
	for(int i=1;i<=n;i++){
		for(;sum+(a[cr]-a[cr-1])*(cr-cl)<=m&&cr<=n;cr++){
			sum+=(a[cr]-a[cr-1])*(cr-cl);
		}
		sum-=a[cr-1]-a[cl];
		ans=max(ans,cr-cl);
		cl++;
	} 
	cout<<ans;
	return 0;
}