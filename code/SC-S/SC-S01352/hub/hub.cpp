#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll a[500005],n,m,z,s,r,b[500005];
int main(){
	freopen("crystal.in.txt","r",stdin);
	freopen("crystal.out.txt","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i = 0;i< n;++i){
		scanf("%lld",&a[i]);
	}
	sort(a,a+n);
	for(int i = 0;i<n-1;++i){
		b[i]=a[i+1]-a[i];
	}
	for(int i = 0;i<=n-1;++i){
		r=m;
		z=1;
		while(r>=0&&z+i<=n-1){
			for(int j =0;j<=z;++j){
				r-=b[i+z];
			}
			++z;
		}
		if(z>s)
			s=z;
	}
	printf("%lld",s);
	return 0;
}