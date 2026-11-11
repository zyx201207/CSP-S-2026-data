#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=500010;
int n,m,a[N],ans=0,d[N];
int sum,bef,f,pre;
void check(int x) {
	bef=sum,pre=f;
	if(f-(a[x]-a[x-1])*bef>=0) {
		sum++;
		f-=(a[x]-a[x-1])*bef;
		return ;
	}
	f-=(a[x]-a[x-1])*bef;
	for(int i=x-1-sum;i<=x;i++) {
		f+=a[x]-a[i];
		sum--;
		if(f>=0) {
			sum++;
			return ;
		}
	}
}
signed main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++) {
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	sum=bef=0,f=pre=m;
	for(int i=1;i<=n;i++) {
		check(i);
		ans=max(ans,sum);
	}
	cout<<ans<<"\n";
	return 0;
}
//Oct31==Dec25?
/*
9 7
-6 -6 -5 -5 1 1 2 2 2

5 8
-3 -1 2 2 7

5 5
1 2 4 8 9

315829
*/