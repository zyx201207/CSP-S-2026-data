#include<cstdio>
#include<algorithm>
int n;
long long m;
long long a[500012];
unsigned long long c[500012];
int BIG_SHOT(){
	bool ok=true;
	for(int i=3;i<=n;i++){
		if(c[i]!=c[i-1]){
			ok=false;
			break;
		}
	}
	if(ok){
		int ans=1;
		long long t=m;
		long long s=c[2];
		int i=1;
		while(t){
			if(t<s*i)break;
			t-=s*i;
			ans++;
			i++;
		}
		return ans;
	}
	
	int maxx=1;
	for(int l=1;l<=n;l++){
		long long cnt=0;
		for(int r=l+1;r<=n;r++){
			cnt+=(r-l)*c[r];
			if(cnt>m)break;
			maxx=std::max(maxx,r-l+1);
		}
	}
	/*for(int l=1;l<=n;l++){
		int cnt=0;
		for(int i=1;l+i<=n&&cnt<=m;i++){
			cnt+=i*c[l+i];
			maxx=std::max(maxx,i+1);
		}
	}*/
	return maxx;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	std::sort(&a[1],&a[n+1]);
	c[1]=a[1];
	for(int i=2;i<=n;i++)c[i]=a[i]-a[i-1];
	//for(int i=1;i<=n;i++)printf("%lld%c",c[i]," \n"[i==n]);
	printf("%d\n",BIG_SHOT());
	return 0;
}
//Oct31==Dec25?
