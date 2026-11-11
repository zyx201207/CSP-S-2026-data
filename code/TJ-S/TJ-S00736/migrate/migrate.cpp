#include<iostream>
#include<cstdio>
using namespace std;
int n;
long long d;
long long x[2000009];
int nx[2000009];
int ju[309][309];
int fu[309];
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	scanf("%d%d",&c,&t);
	while(t--) {
		scanf("%d%lld",&n,&d);

		for(int i=1; i<=n; i++) {
			scanf("%lld",&x[i]);
			fu[i]=0;
		}
		if(n==1) {
			cout<<0<<"\n";
			continue;
		}
		if(c>=11&&c<=12) {
//			cout<<x[2]-x[1]<<' '<<d<<"\n";
			d/=(x[2]-x[1]);
			if(d<=1) {
				cout<<0<<"\n";
				continue;
			}
			cout<<max(0ll,n-2*d+1)<<"\n";
			continue;
		}
		int o=n;
//		cout<<"skd";
		for(int i=n; i>=1; i--) {
			while(x[o]-x[i]>d) {
				o--;
			}
			nx[i]=o;
		}
		int su=0;
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				int k=i;
//			   cout<<"sk";
               su=0;
				while(k<j) {
					if(k==nx[k]) {
						su=1e9;
						break;
					}
					k=nx[k];
					su++;
				}
				ju[i][j]=su;
			}
		}
//		cout<<ju[1][4]<<endl;
		su=1;
		bool bb;
		long long sum=0,ss;
		for(int i=1; i<=n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(ju[i][j]==1e9) {
					break;
				}
				bb=true;
				int k=i;
				while(k<j) {
					fu[k]=su;
					k=nx[k];
				}
				ss=0;
				for(k=i+1; k<j; k++) {
					if(fu[k]!=su) {
						if(ju[i][k]+ju[k][j]==ju[i][j]) {
							ss++;
						}
					}
				}
				if(ss==1) {
					sum++;
				}
				su++;
			}
		}
		cout<<sum<<"\n";
	}
	return 0;
}
