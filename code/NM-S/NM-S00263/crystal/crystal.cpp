#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,maxx,sum,ans,minn,anss;
int a[500010];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	cin>>a[1];
	minn=a[1];
	maxx=a[1];
	for(int i=2;i<=n;i++){
		cin>>a[i];
		if(maxx<a[i]) maxx=a[i];
		if(minn>a[i]) minn=a[i];
	}
	sort(a+1,a+n+1);
	for(int i=minn;i<=maxx;i++){
		sum=0,ans=0;
		int pos=upper_bound(a+1,a+n+1,i)-a;
		for(int j=pos;j>=0;j--){
			if(a[j]>i) continue;
			sum+=i-a[j];
			if(sum<=m) ans++;
			else break;
		}
		anss=max(anss,ans);
	}
	cout<<anss;
	return 0;
} 
