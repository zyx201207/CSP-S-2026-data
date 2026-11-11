#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],sum,cnt=1,ans[500005],mx;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++){
		s[i]=s[i-1]+(i-cnt)*(a[i]-a[i-1]);
		if(s[i]>m){
			while(s[i]>m){
				s[i]-=(a[i]-a[cnt++]);
				ans[i]++;
			}
		}
	}
	for(int i=1;i<=n;i++){
		ans[i]=1-ans[i];
	}
	for(int i=2;i<=n;i++){
		ans[i]+=ans[i-1];
		mx=max(ans[i],mx);
	}
	cout<<mx;
	return 0;
}
/*
诱捕器
//	freopen("crystal.in","r",stdin);
//	freopen("crystal.out","w",stdout);
思路
要求尽量多地获得水晶 
枚举n个水晶作为基准，去算以这个水晶作为基准对答案产生的影响
对答案产生的影响分为获得与丢弃两个方面 
最后将n个方案获得与丢弃影响相加，求前缀和 
最后取最大值，即为所求 
枚举O(n)，回退一共O(n)，总的复杂度O(n)
洛谷号 Logic_Lower_bound ，欢迎互关
*/
