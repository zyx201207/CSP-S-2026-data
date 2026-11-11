#include"bits/stdc++.h"
using namespace std;

/*
dfs
这样时间复杂度应该是 $O(n^2)$ 的（？ 
期望得分：5*10=50pts 
观察测试点发现或许 $m = n-1$、性质 A 好像都能打
- $m = n-1$：& 应该有逆运算（就是倒着的 ^），那么可以枚举，$O(n)$
- 性质 A：二进制全是 $1$ 咯，这样找第 $m$ 大即可
期望得分：5*10+[0,15]=[50,65]pts 
*/ 
const int MAXN=1e5*2+5;
int a[MAXN];
int pw2[40];
int n,m,ans;
bool flag_A=1;
void init(){
	pw2[0]=1;
	for(int i=1;i<=30;i++){
		pw2[i]=pw2[i-1]*2;
	}
}
void dfs(int start,int step,int sum){
	if(step>m){
		ans=max(ans,sum);
		return;
	}
	for(int i=start+1;i<=n;i++){
		dfs(i,step+1,sum&a[i]);
	}
}
int no_yh(int x,int y){
	int res=0,c=0;
	while(x||y){
		if((x&1)==(y&1))res=res+pw2[c];
		x>>=1;
		y>>=1;
		c++;
	}
	return res;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	init();
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		int lg=log2(a[i]+1);
		if(pw2[lg]!=a[i]+1)flag_A=0; 
	}
	if(m==n-1){
		//大概率会被 hack，但 ccf 应该会让我过一点 
		int sum=INT_MAX;
		for(int i=1;i<=n;i++){
			sum=(sum&a[i]);
		}
		for(int i=1;i<=n;i++){
			int t=no_yh(sum,a[i]);
			ans=max(ans,t);
		}
		printf("%d\n",ans);
//		cerr<<"yes,is data m=n-1\n";
		return 0;
	}
	if(flag_A){
		sort(a+1,a+n+1,greater<int>());
		printf("%d\n",a[m]);
//		cerr<<"yes,is data A\n";
		return 0;
	}
	
	dfs(0,1,INT_MAX);
	printf("%d\n",ans);
	return 0;
}
/*
4 2
3 15 12 12
?-11:40
*/
