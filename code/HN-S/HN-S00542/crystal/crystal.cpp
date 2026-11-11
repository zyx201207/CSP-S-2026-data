#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,a[N],m,maxc=INT_MIN;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int cnt=0,x=m;
		for(int j=1;j<=i;j++){
			x=x-a[i]+a[j];
			if(x<0) continue;
			cnt++;
		}
		maxc=max(maxc,cnt);
	}
	cout<<maxc;
	return 0;
}
