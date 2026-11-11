#include<bits/stdc++.h>
#define maxn 500005
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
long long d[maxn];
long long a[maxn];
long long n,m,ans;
bool cmp(long long x,long long y){
	return x<y;
}
bool memjff;

int main(){
//	printf("%.8lfMB\n",(&memjff-&memjfs)/1024.0/1024.0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);
//	cout.tie(0);
	read(n);read(m);
	
	for(long long i=1;i<=n;i++){
		read(a[i]);
	}
	sort(a+1,a+n+1,cmp);
	
	for(long long i=1;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	
	for(long long t=1;t<=n;t++){
		long long ad=0;
		bool ctf=0;
		
		for(long long i=t+1;i<=n;i++){
			ad+=d[i]*(i-1);
			
			if(i==n){
				ans=max(ans,i-t);
				ctf=1;
				break;
			}
			
			if(ad>m){
				ans=max(ans,i-t);
				break;
			}
		}
		
		if(ctf){
			break;
		}
	}
	
	printf("%lld",ans);
	return 0;
}
