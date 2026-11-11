//我去了，这个第二题题目复杂度堪比语文一篇800字的文言文阅读理解
//那个三四题更是难到飞起
//出题老师真是个奇迹
//感谢出题老师
//我明年还来
//我就不信明年还是这些出题老师
//今年就容我思考3个小时（写这道题花了1h）的人生了 
//我去，这第2题还出错题了
//还好我没写 
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[1000000006],d[1000000006];
long long minn=1e9,summ=0;
bool check(long long h){
	//条件： 有h个水晶相等，且代价<=m
	for(int i=1;i<=n-h;i++){
		for(int j=1;j<=h;j++){
			summ+=d[j];
		}
		minn=min(summ,minn);
	}
	if(minn>m&&h<0){
		return false;
	}else{
		return true;
	}
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		d[i]=a[i]-a[i-1];
	}
	long long l=a[1],r=a[n];
	long long mid=(l+r)/2-(l+r)%2;
	while(l<r-1){//能用多少个水晶合成 
		if(check(mid)){
			l=mid;
			mid=(l+r)/2;
		}else{
			r=mid;
			mid=(l+r)/2;
		}
	}
	cout<<mid;
	return 0;
}
