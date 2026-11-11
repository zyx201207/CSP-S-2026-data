#include<bits/stdc++.h>
using namespace std;
namespace solve1{
	int n,h,t,good;
	long long d,a[5010],f[5010],g[5010],gans;
	void s1(){
		scanf("%d",&t);
		while(t--){
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++)
				scanf("%lld",&a[i]);
			gans=0;
			for(int i=1;i<=n;i++){
				good=i;
				f[i]=0;
				g[i]=1;
				for(int j=i+1;j<=n;j++){
					while(a[j]-a[good]>d)
						good++;
					if(good==j)
						break;
//					cout<<j<<" "<<good<<","<<a[j]<<" "<<a[good]<<"|"<<d<<endl;
					f[j]=f[good]+1;
					g[j]=0;
					for(int k=good;k<=good+2&&f[k]==f[good];k++)
						g[j]+=g[k];
					if(g[j]>3)
						g[j]=3;
					else if(g[j]==2){
						gans++;
//						cout<<i<<","<<j<<endl;
					}
				}
			}
			printf("%lld\n",gans);
		}
	}
}
namespace solve2{
	int n,t;
	long long a[2000010],d;
	void s2(){
		scanf("%d",&t);
		while(t--){
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++)
				scanf("%lld",&a[i]);
			if(n==1){
				puts("0");
				continue;
			}
			long long c=d/(a[2]-a[1]);
			if(c<=1){
				puts("0");
				continue;
			}
			printf("%lld\n",max(n-2*c+1,0ll));
		}
	}
}
namespace solve3{
	int n,t;
	long long a[2000010],d,rm[2000010]={1};
	void s3(){
		scanf("%d",&t);
		while(t--){
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++)
				scanf("%lld",&a[i]);
			for(int i=1;i<=n;i++){
				rm[i]=rm[i-1];
				while(a[rm[i]+1]-a[i]<=d&&rm[i]<n)
					rm[i]++;
//				cout<<i<<":"<<rm[i]<<"\n";
			}
			long long ans=0;
			for(int i=1;i<=n;i++){
				int f=rm[i];
				if(f>i+1)
					ans+=rm[f-1]-rm[f-2];
			}
			printf("%lld\n",ans);
		}
	}
}
int c;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d",&c);
	if(c<=10){
		solve1::s1();
	}
	else if(c==11||c==12){
		solve2::s2();
	}
	else if(c==13||c==14){
		solve3::s3();
	}
	return 0;
} 
