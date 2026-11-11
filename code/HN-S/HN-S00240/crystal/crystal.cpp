#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=500500;
int n,m,a[N],l,mid;
int cha(int x,int y){
	int z=0;
	for (int i=x;i<y;i++){
		z=z+a[y]-a[i];
	}
	return z;
}
bool pan(int x){
	int s=1000000000000000001;
	for (int i=1;i<n-x+2;i++){
		s=min(s,cha(i,i+x-1));
	}
	return (s<=m);
}
signed main()
{

	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin.tie(0);cout.tie(0);
	cin>> n >> m;
	for (int i=1;i<=n;i++){
		cin>> a[i];
	}
	sort(a+1,a+n+1);
	int r=n;
	while (l<=r){
		mid=(l+r)>>1;
		if (pan(mid)) l=mid+1;
		else r=mid-1;
	}
	cout<< r;

return 0;
}

