//SN-S00659 马星辰 西安市曲江第一学校 
#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],ans;
long long check(long long p){
	long long minm=1000000000000000000;
	for (long long i = p;i <= n;i++){
		minm=min(minm,(a[i]-a[i-1])*p-(a[i]-a[i-p]));
	}
	return minm;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for (int i = 1;i <= n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for (int i = 1;i <= n;i++){
		a[i]+=a[i-1];
	}
	ans=0;
	for (long long i = ((long long)1<<60);i;(i>>=(long long)1)){
		if (i<=n&&check(ans+i)<=m)//ans+i颗水晶至少要多少次x x xxx操作
			ans+=i; 
	}
	cout<<ans;
	return 0;
}
