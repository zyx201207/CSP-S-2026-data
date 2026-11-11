#include<bits/stdc++.h>
#define maxn 2000005
using namespace std;

bool memjfs;
void read(long long &numx){
	register bool is_minus=0;
	register char xxx=getchar();
	numx=0;

	for(;xxx<'0'||xxx>'9';xxx=getchar()){
		if(xxx=='-'){
			is_minus=1;
		}
	}

	for(;xxx>='0'&&xxx<='9';xxx=getchar()){
		numx=(numx<<3)+(numx<<1)+(xxx^48);
	}

	if(is_minus){
		numx=-numx;
	}
}
long long a[maxn];
long long _,T,n,d,ans;
bool isi(long long x){
	for(long long i=1;i<=n;i++){
		if(a[i]==x){
			return 1;
		}
	}
	
	return 0;
}
bool check(long long x,long long y){
	long long nd=abs(x-y);
	
	if(nd==1){
		return 0;
	} else {
		for(long long i=x;i<=y;i++){
			if(isi(i)){
				return 1;
			}
		}
		
		return 0;
	}
}
bool memjff;

int main(){
//	printf("%.8lfMB\n",(&memjff-&memjfs)/1024.0/1024.0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	read(_);read(T);
	
	for(long long task=1;task<=T;task++){
		memset(a,0,sizeof(a));
		ans=0;
		read(n);read(d);
		
		for(long long i=1;i<=n;i++){
			read(a[i]);
		}
		
		for(long long i=1;i<=n;i++){
			for(long long j=1;j<=n;j++){
				if(i!=j&&check(a[i],a[j])){
					ans++;
				}
			}
		}
		
		printf("%lld",ans);
	}
	return 0;
}
