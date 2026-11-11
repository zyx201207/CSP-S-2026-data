#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],ed,ans;
//ed:上一轮区间终点
//ans:最大区间长度(输出)
//m:当前剩余可操作次数(每次用长度*差值) 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
		cin>>a[i]; 
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){//以i为第一个开始操作 
		if(n-i+1<=ans||ed==n)	break;//全部使用也不会更多
		m+=a[ed]-a[i-1];
		long long lenth=ed-i+1;
		while(lenth<n&&m>=lenth*(a[ed+1]-a[ed])){
			m-=lenth*(a[ed+1]-a[ed]);
			++ed;
			++lenth;
		}
		ans=max(ans,lenth);
	}
	cout<<ans;
	return 0;
} 
