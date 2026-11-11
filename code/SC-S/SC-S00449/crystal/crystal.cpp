/*
显然此题（不）用dp求解 
我们要先找基准点
1.因为我们只能增加水晶能量值所以只用考虑基准点与前面点的差
2.贪心的想因该选基准点前面的最多能选的点，所以区间起点不用考虑
所以我们因枚举所有的点为基准点的情况再通过预处理的数组c来看能选多少个点 
c[i]表示第i个数与前面所有数的差之和 转移方程为c[i]=c[i-1]+(i-1)(a[i]-a[i-1])
这时若直接用c[i]与m作比较，得出能否选所有的i以前的点但显然不对
应为最小能在范围内的数量 
那么从i至j(j<=i)的差为多少呢？
显然为c[i]-(i与所有j前的数的差)
i与所有j前的数的差为 (j-1)a[i]-sum[j-1]
所以原式=c[i]-((j-1)a[i]-sum[j-1])
*/
#include<bits/stdc++.h>//qwq
using namespace std;
const long long N=2e5+10,M=1e8+10;
long long n,m,cnt,ans=-0x3f3f3f3f3f3f3f3f;
long long a[N],c[N],sum[N]; //c[i]表示第i个数与前面所有数的差之和
inline long long read(){
	long long a=0,b=1;
	char c=getchar();
	while(!isdigit(c)&&c!='-')c=getchar();
	if(c=='-'){
		b=-1;
		c=getchar();
	}
	while(isdigit(c)){
		a=a*10+c-'0';
		c=getchar();
	}
	return a*b;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	} 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
		c[i]=c[i-1]+(i-1)*(a[i]-a[i-1]);
	}
	for(int i=1;i<=n;i++){
		long long node=0;
		bool f=0;
		long long l=1,r=i;
		while(l<=r){ 
			int mid=(l+r)>>1;
			if(c[i]-((mid-1)*a[i]-sum[mid-1])<=m){//在范围内就选
				node=mid;
				f=1;
				r=mid-1;
			}else{
				l=mid+1;
			}
		}
		if(f)ans=max(ans,i-node+1);
	}
	if(ans>=0)cout<<ans;
	else cout<<0;
	return 0;
}