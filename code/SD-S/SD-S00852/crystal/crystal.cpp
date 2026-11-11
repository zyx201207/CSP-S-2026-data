#include <bits/stdc++.h>
using namespace std;
typedef long long lint; 
lint n,m,a[500005],b[500005];
bool p(int x){
	lint z=m+10;
	for(int i=x;i<=n;i++){
		int r=i,l=i-x+1;
		z=min(z,1ll*a[r]*x-(b[r]-b[l-1]));
	}
	return z<=m;
}
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	int l=-1,r=n+10;
	while(l+1<r){
		int mid=(l+r)>>1;
		if(p(mid)){
			l=mid;
		}else{
			r=mid;
		}
	}
	cout<<l;
	return 0;
}

