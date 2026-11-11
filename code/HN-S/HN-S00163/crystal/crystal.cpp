#include<iostream>
#include<cstdio>
#include<algorithm>
#define int long long
using namespace std;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n,m,maxn=0;
	cin>>n>>m;
	int a[n+1],s[n+1];
	s[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	while(n--){
		int _m=m,ans=0;
		for(int i=1;i<=n;i++){
			s[i]=a[n]-a[i];
		}
		sort(s+1,s+n+1);
		for(int i=1;i<=n;i++){
			if(_m-s[i]<0)break;
			_m-=s[i];
			ans++;
		}
		maxn=max(ans,maxn);
	}
	cout<<maxn;
	return 0;
}
