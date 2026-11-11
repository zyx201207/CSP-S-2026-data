#include<bits/stdc++.h>
using namespace std;
const int M=500005;
long long l[M],k[M],p[M],u[M],a[M];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	long long n,m,v=0,t=0,s=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>l[i];
	}
	sort(l+1,l+1+n);
	for(int i=1;i<=n;i++){
		k[i]=l[i]-l[i-1];
		p[i]=k[i]*(i-1);
		a[i]=a[i-1]+l[i];
		if(a[i]<=v){
			v=a[i];
			t=i;
		}
	}
	u[1]=p[1];
	for(int i=2;i<=n;i++){
		u[i]=u[i-1]+p[i];
	}
	for(int i=n;i>=1;i--){
		if(u[i]<=m){
			cout<<i;
			return 0;
		}
	}
	return 0;
}
