#include<bits/stdc++.h>
using namespace std;
long long qkread() {
	long long n1=0,qkf=1;
	char qkc=getchar();
	while(qkc<'0'||qkc>'9') {
		if(qkc=='-') qkf=-1;
		qkc=getchar();
	}
	while(qkc>='0'&&qkc<='9') {
		n1=n1*10+qkc-48;
		qkc=getchar();
	}
	return n1*qkf;
}
long long c,T,n,D,a[5001],d[5001][5001],ct[5001][5001],ans;
int main() {
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=qkread(),T=qkread();
	while(T--) {
		memset(d,0x3f,sizeof(d)),memset(ct,0,sizeof(ct));
		ans=0;
		n=qkread(),D=qkread();
		for(int i=1; i<=n; i++) d[i][i]=0;
		for(int i=1; i<=n; i++) a[i]=qkread();
		for(int i=1; i<n; i++) {
			for(int j=i+1; j<=n; j++) {
				if(a[j]-a[i]<=D) d[i][j]=1,ct[i][j]=1;
			}
		}
		for(int k=1; k<=n; k++) {
			for(int i=1; i<n; i++) {
				for(int j=i+1; j<=n; j++) {
					if(d[i][j]>d[i][k]+d[k][j]) {
						d[i][j]=d[i][k]+d[k][j];
						ct[i][j]=ct[i][k]*ct[k][j];
					} else if(d[i][j]==d[i][k]+d[k][j]) ct[i][j]+=ct[i][k]*ct[k][j];
				}
			}
		}
		for(int i=1; i<n; i++) {
			for(int j=i+1; j<=n; j++) ans+=(ct[i][j]==2);
		}
		cout<<ans<<"\n";
	}
	return 0;
}
