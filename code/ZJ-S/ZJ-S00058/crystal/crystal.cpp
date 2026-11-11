#include<bits/stdc++.h>
using namespace std;
long long n,m,a[555555],f[555555];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	memset(f,0,sizeof(f));
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)f[i]=f[i-1]+a[i];
//	for(int i=1;i<=n;i++)printf("%lld %lld\n",f[i],ff[i]);
	long long ans=1;
	for(int i=1;i<=n;i++){
		if(i+ans-1>=n)break;
		bool ok=1;
		for(;ok;){
			int fans=ans+1;
			long long l=i,r=i+fans-1;
			if(r>n){ok=0;continue;}
			long long res=-f[r]+f[l-1]+(r-l+1)*a[r];
//			printf("%d %d %lld\n",l,r,res);
			if(res>m)ok=0;
			else ans=fans;
		}
	}
	printf("%d",ans);
}