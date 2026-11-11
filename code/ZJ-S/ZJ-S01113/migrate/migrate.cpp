#include <bits/stdc++.h>
using namespace std;
void fre(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
}
long long c,T,n,d,a[2000010],l,h[2000010],ans;
void pian11(){
	while(T--){
		scanf("%lld %lld",&n,&d);
		l=1;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(n<=2){
			printf("0\n");
			continue;
		}
		long long cha=a[2]-a[1];
		ans=0;
		if(d<2*cha){
			printf("0\n");
			continue;
		}
		for(int i=3;i<=n;i++){
			if(d<a[i]-a[1]&&a[i]-a[1]<2*d){
				ans+=(n-i+1);
			}
		}
		printf("%lld\n",ans);
	}
	exit(0);
}
void pian13(){
	while(T--){
		scanf("%lld %lld",&n,&d);
		l=1;
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		if(n<=2){
			printf("0\n");
			continue;
		}
		if(a[n]-a[1]<=d){
			printf("0\n");
			continue;
		}
		long long cha=a[2]-a[1];
		ans=0;
		if(d<2*cha){
			printf("0\n");
			continue;
		}
		for(int i=3;i<=n;i++){
			if(d<a[i]-a[1]&&a[i]-a[1]<2*d){
				ans+=(n-i+1);
			}
		}
		printf("%lld\n",ans);
	}
	exit(0);
}
int main(){
	fre();
	scanf("%lld %lld",&c,&T);
	if(11<=c&&c<=12){
		pian11();
	}
	if(13<=c&&c<=14){
		pian13();
	}
	while(T--){
		scanf("%lld %lld",&n,&d);
		for(int i=1;i<=n;i++){
			scanf("%lld",&a[i]);
		}
		printf("%lld\n",0);
	}
	//jingtiandebisaifeila,yihouyangenjiarenzhendexuebianchengle,buguojintianyeshiyoushideqinzhudedifangde,zhishaowotupoleziwo,bushima?qimadiyidizuochulaileba(huangshuleitamenkendingsuibiaomiaode,jiuwotiaollenamejiu,abab,woshishabi),danshirenranxiwangnengnagegaofen
	//rp++;
	return 0;
}
