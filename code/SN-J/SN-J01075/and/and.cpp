#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m;
long long arr[N],ans;
long long pow_(long long a,int b){
	long long sum = 1;
	for(int i=1;i<=b;i++)
		sum *= a;
	return sum;
}
long long and_(long long x,long long y){
	bool a[35]={0}, b[35]={0};
	long long z=0;
	for(int i=30;i>=0;i--){
		int t=pow_(2,i);
		if(t<=x){
			x-=t;
			a[i] = 1;
		}
		if(t<=y){
			y-=t;
			b[i] = 1;
		}
	}
	for(int i=0;i<=30;i++)
		z += (int)(a[i]&&b[i])*pow(2,i);
	return z;
}
void dfs(int now,long long sum,int num){//当前到第i个数  结果为sum  用了m个数 
	if(num==m){
		ans = max(ans,sum);
		return;
	}
	if(now==n+1)	return;
	dfs(now+1,sum,num);//不选这一个
	dfs(now+1,and_(sum,arr[now]),num+1); 
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	scanf("%d %d",&n,&m);
	for(int i=1;i<=n;i++)
		scanf("%lld",&arr[i]);
	dfs(1,2147483647,0);
	//2147483647 = (111 1111 1111 1111 1111 1111 1111 1111)2进制 
	printf("%lld\n",ans);
	
	return 0;
} 
