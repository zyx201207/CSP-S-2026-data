#include <bits/stdc++.h>
using namespace std;
int c,T;
namespace sub0{
	const int N=3005;
	int n,f[N];
	long long d,x[N],g[N],ans;
	void main(){
		while(T--){
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++)
				scanf("%lld",&x[i]);
			ans=0;
			for(int s=1;s<=n;s++){
				for(int i=s+1;i<=n;i++) f[i]=n+1,g[i]=0;
				f[s]=0; g[s]=1;
				for(int i=s+1;i<=n;i++){
					for(int j=i-1; j>=s&&x[i]-x[j]<=d; j--){
						if(f[j]+1==f[i]) g[i]+=g[j];
						if(f[j]+1<f[i]) f[i]=f[j]+1,g[i]=g[j];
					}
					if(g[i]==2) ans++;
				}
			}
			printf("%lld\n",ans);
		}
	}
}
namespace subB{
	const int N=2e6+5;
	int n;
	long long d,x[N],ans;
	void main(){
		while(T--){
			scanf("%d%lld",&n,&d);
			for(int i=1;i<=n;i++)
				scanf("%lld",&x[i]);
			if(x[n]-x[1]<=d) {printf("0\n");continue;}
			ans=0;
			for(int i=1;i<=n;i++){
//				cout<<"i="<<i<<"\n";
				int j=upper_bound(x+1,x+n+1,x[i]+d)-x-1;
				int k1=upper_bound(x+1,x+n+1,x[j]+d)-x-1;
//				cout<<" j="<<j<<"\n k1="<<k1<<"\n";
				if(i==j-1){ans+=k1-j;continue;}
				int k2=upper_bound(x+1,x+n+1,x[j-1]+d)-x-1;
//				cout<<" k2="<<k2<<"\n";
				if(i==j-2){ans+=k2-j;continue;}
				int k3=upper_bound(x+1,x+n+1,x[j-2]+d)-x-1;
//				cout<<" k3="<<k3<<"\n";
				ans+=k2-k3;
			}
			printf("%lld\n",ans);
		}
	}
}
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	scanf("%d%d",&c,&T);
	if(c==13||c==14) subB::main();
	else sub0::main();
	return 0;
}
