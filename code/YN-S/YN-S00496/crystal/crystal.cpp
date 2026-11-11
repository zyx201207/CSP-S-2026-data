#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500005],b[500005],c[500005];
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	sort(a,a+n);
	for(int i=n-1;i>0;i--){
		b[i]=(a[i]-a[i-1]);
	}
	for(int i=1;i<n;i++){
		c[i]=c[i-1]+b[i];
	}
	long long k=m,p1=0,p2=0,ans=0;
	for(int i=1;i<n;i++){
		p2++;
		int x=b[i]*(p2-p1);
		k-=x;
		while(k<0){
		k+=(c[p2]-c[p1]);
		p1++;
		}
//		cout<<(p2-p1)<<' '<<p1<<' '<<p2<<' '<<k<<endl;
		ans=max(ans,(p2-p1));
	}
	cout<<ans+1;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7

*/