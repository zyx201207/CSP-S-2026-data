#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,a[500011],s[500011];
//二分答案是一种好的选择吗
//是否具备单调性？我想是的
//先对其排序 应为用于合成的他们一定是相邻的
//我们解决过逛画展不是吗？
//但是 我们并不知道他们在什么地方相似
//是的 注意到！“将其能量值增加1”所以一定是向最大的那一个靠齐！
bool check(long long x){
	for(int i=x;i<=n;i++){
		if(a[i]*x-(s[i]-s[i-x])<=m)return 1;
	}
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	long long l=1,r=n;
	while(l<=r){
		long long mid=(l+r)/2;
		if(check(mid)){
			//如果可以
			ans=mid;
			l=mid+1;
		}
		else r=mid-1;
	}
	cout<<ans;
}