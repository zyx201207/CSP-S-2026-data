#include<cstdio>
#include<algorithm>
const int MAXN=500006;
long long a[MAXN];
long long b[MAXN];
const long long INF=0x3f3f3f3f3f3f3f3f;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m; 
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	std::sort(&a[1],&a[n+1]);
	for(int i=2;i<=n;i++)b[i]=a[i]-a[i-1];
	
	long long max=-INF;
	for(int i=2;i<=n;i++){
		long long sum=0;
		int num=1;
		for(int j=i;j>=2&&sum<m;){
			if(sum+b[j]<=m){
				sum+=b[j];
				num++;
			}else{
				break;
			}
			if(j-1>=2)j--;
			else break;
		}	
		if(num>max&&sum<=m)max=num;
	}

	printf("%d\n",max);
	return 0;
} 
