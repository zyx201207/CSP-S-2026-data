#include<bits/stdc++.h>
using namespace std;
long long a[2000009];
long long b[2000009];
long long e[2000009];
long long f[2000009];
int main(){
//	freopen("migrate4.in","r",stdin);
//	freopen("hywhywhywhywh.out","w",stdout);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
	long long c,T;
	scanf("%lld%lld",&c,&T);
	while(T--){
		long long n,d,ans=0;
		scanf("%lld%lld",&n,&d);
		for(long long i=1;i<=n;i++){
			scanf("%lld",&a[i]);
			f[i]=100000000000000000ll;
		}
		for(long long k=n;k>=1;k--){
			for(long long i=k;i<=n;i++){
				f[i]=100000000000000000ll;
			}
			a[n+1]=100000000000000000ll;
			long long r=k,l=k+1;
			f[k]=0;
			for(long long i=k;i<=n;i++){
				while(r<=n&&a[r]-a[i]<=d){
					r++;
				}
				l=max(l,i+1);
				for(long long j=l;j<r;j++){
					f[j]=f[i]+1;
				}
				l=r;
			}
			l=k,r=k;
			b[k]=1;
			e[k]=1;
			for(long long i=k+1;i<=n;i++){
				if(f[i]!=f[i-1]){
					r=i-1;
				}
				while(l<=r&&(a[i]-a[l]>d||f[r]>f[l])){
					l++; 
				}
				b[i]=e[r]-e[l-1];
				e[i]=e[i-1]+b[i];
			}
			for(long long i=k;i<=n;i++){
				if(b[i]==2){
					ans++;
				}
				b[i]=0;
				e[i]=0;
				f[i]=0;
			}
		}
		printf("%lld\n",ans);
	}
	return 0;
}

