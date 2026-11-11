#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500005];
long long s[500005];
long long ans; 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(long long i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++)
	{
//		cout<<a[i]<<' ';
		s[i]=s[i-1]+a[i];
	}
	for(long long i=1;i<=n;i++){
		long long p=a[i]*i-s[i];
//		cout<<p<<" "<<i<<" ";cout<<p<<" ";
		if(p>m)
		{
//			cout<<p<<" ";
//			cout<<p<<" "<<s[i]<<" ";
			break;
		 } else{
		 	ans=i;
		 }
	}
	cout<<ans;
	return 0;
}

/*
这里是游记喵

14：30 开题发现没有字符串  也没有数学 

t1 看起来是简单题 t2 看起来是图论  t3 没看懂 应该是dp t4 是树上问题  又 又又又又又又没有考数据结构（（（（（（（（（（ 

14:54 写完了 发现最后一个样例有问题 挂个拍子 

15:10 拍了半天发现没用 故重构 

15:30 发现思路假了  调不出来了开t2

16：10 可以将一条线路当成一个点  
*/
