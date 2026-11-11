#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[2100000],m,z=1,s;
signed main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=(1<<30);i>=1;i>>=1){
		int l=z,r=n,S=-1;
		while(l<=r){
			int md=(l+r)>>1;
			if(a[md]%(i*2)<i)l=md+1;
			else r=md-1,S=md;
		}
		if(S==-1)continue;
		if(n-S+1<m){
			for(int i2=z;i2<=n;i2++)a[i2]%=i;
			sort(a+z,a+n+1);
			continue;
		}
		z=S;
		s+=i;
	}
	cout<<s;
	return 0;
}
