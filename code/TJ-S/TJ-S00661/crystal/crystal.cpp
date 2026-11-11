#include<bits/stdc++.h>
using namespace std;
const int N=5e5+100;
long long n,m,a[N],d,t[N],tmp[N],cnt[N];

bool f1=true;
long long dfs(long long k){
	long long r=0;
	if(k>m){
		int l=0;
		memset(cnt,0,sizeof(cnt));
		for(int i=1;i<=n;i++){
			tmp[i]=t[i];
		}
		sort(tmp+1,tmp+n+1);
		for(int i=1;i<=n;i++){
			if(i==1) l++;
			if(i!=1&&a[i]!=a[i-1]) l++;
			cnt[l]++;
		}
		for(int i=1;i<=l;i++){
			r=max(r,cnt[i]);
		}
	}
	for(int i=1;i<=n;i++){
		t[i]++;
		r=max(r,dfs(k+1));
	}
	return r;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
		if(i==2) d=a[i]-a[i-1];
		if(i!=1&&a[i]!=a[i-1]+d) f1=false;
	}
	for(int i=1;i<=n;i++){
		t[i]=a[i];
	}
	if(f1){
		for(long long i=sqrt(m);i>=1;i--){
			if(m/d>=(long long)(i+1)*i/2){
				printf("%d",i+1);
				return 0;
			}
//		}
//		long long l=1,r=sqrt(m)+(!(sqrt(m)*sqrt(m)==m)),mid;
//		while(l<=r){
//			mid=(l+r)/2;
//			//if(mid<=(double)sqrt((double)1.0*2*m/d+1/4)-1.0/2) l=mid+1;
//			if(m/d>=(mid+1)*mid/2) l=mid+1;
//			else r=mid-1;
//		}
//		printf("%lld",r+1);
		}
	}
	if(n<=5&&m<=10){
		printf("%lld",dfs(1));
	}else{
		printf(0); 
	}
	return 0;
}
