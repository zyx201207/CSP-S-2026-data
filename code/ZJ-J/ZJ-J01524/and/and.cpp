#include<bits/stdc++.h>
using namespace std;
long long n,m,a[234567],ans,b[234567],bb;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	long long x;
	x=((long long)1)<<50;
	while(x){
//		cout<<x<<" "<<ans<<endl;
		bb=0;
		for(int i=1;i<=n;i++)
		if(a[i]&x)
		b[++bb]=a[i];
		if(bb>=m){
			for(int i=1;i<=bb;i++)a[i]=b[i];
			n=bb;
			ans+=x;
		}
		x=x/2;
	}
	cout<<ans<<endl;
	return 0;
}
//4 2
//3 15 12 12

