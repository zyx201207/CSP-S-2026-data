/*
对于每一个数字，二分查找 找到满足再往左就要使用>m次操作的数字
i-j+1是答案
记录最大值 
5 5 
1 2 4 8 9
5 8 
-3 -1 2 2 7
9 5
99 99 99 99 1 2 99 3 100
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
long long n,m;
long long a[N],f[N];
int l=0,r=0,mid=0;
int fix(int x){
	r=x;l=1;
	long long tmp_ans=x;
	while(l<=r){
		mid=(l+r)>>1;
		long long tmp=a[x]*(x-mid+1)-(f[x]-f[mid-1]);
		if(tmp<=m){//可以继续扩大范围
			r=mid-1;
			tmp_ans=mid;
		}
		else	l=mid+1;
	}
	return tmp_ans;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%llu",&n);
	scanf("%llu",&m);
	for(int i=1;i<=n;++i){
		scanf("%llu",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		f[i]=f[i-1]+a[i];
	}
	int ans=1;
	for(int i=1;i<=n;++i){
		int tmp=fix(i);
		ans=max(ans,i-tmp+1);
	}
	cout<<ans;
	return 0;
}
