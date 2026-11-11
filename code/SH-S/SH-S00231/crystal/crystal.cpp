#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5+10;
long long a[N],dif[N],f[N],sum[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int fl=1;
	for(int i=2;i<=n;i++) {
		dif[i]=a[i]-a[i-1];
		if(dif[i-1] && dif[i]!=dif[i-1])fl=0;
	}
	if(fl) {
		int s=1,k=dif[n],ma=0;
		for(int i=2;i<=n;i++) {
			s+=k*i;
			if(s<=m) {
				ma=max(ma,i+1);
			}
			else break;
		}
		cout<<ma;
		return 0;
	}
	int ma=1;
	for(int i=1;i<=n;i++) {
		f[i]=0;
		if(n-i+1<=ma) break;
		for(int j=i+1;j<=n;j++) {
			f[j]=f[j-1]+dif[j]*(j-i);
			if(f[j]<=m)ma=max(ma,j-i+1);
			else break;
		}
	}
	cout<<ma;
	return 0; 
}
