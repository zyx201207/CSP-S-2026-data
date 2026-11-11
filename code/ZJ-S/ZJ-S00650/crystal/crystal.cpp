/*
froepen(".out","r",stdout);
//freopen(".in","w",stdin);
#include<bits\stdc++.h>
*/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[500005];
int check(int x){
	int mn=0x3f3f3f3f3f3f3f3f;
	int cnt=0;
	for(int i=1;i<=x;i++){
		cnt+=a[x]-a[i];
	}
	mn=cnt;
	for(int i=x+1;i<=n;i++){
		cnt-=a[i-1]-a[i-x];
		cnt+=(a[i]-a[i-1])*(x-1);
		mn=min(mn,cnt);
	}
	return mn<=m;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	#ifndef hyk0YF0Gamer
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	#endif
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	int l=1,r=n,ans=1;
	while(l<=r){
		int mid=l+r>>1;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}
		else r=mid-1;
	}
	cout<<ans<<'\n';
	return 0;
}
/*
ver 1:expected 100pts time 10min
time complexity:O(n log n)
*/
