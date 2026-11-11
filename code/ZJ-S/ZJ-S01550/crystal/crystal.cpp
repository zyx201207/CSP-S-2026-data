#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+10;
int a[N],b[N],t,w,ma,n,m,i;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	t=1;
	for(w=1;w<=n;w++){
		b[w]=b[w-1]+a[w];
		while(a[w]*(w-t+1)-b[w]+b[t-1]>m)t++;
		ma=max(ma,w-t+1);

	}
	cout<<ma;
	return 0;
}