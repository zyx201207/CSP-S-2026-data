/*
看似三分，实则有相同答案的位置。
我们先排个序
我们发现肯定是集体变成某一个数
虽然不一定是中位数
双指针
对与排序后的每一个 a[i]，都找出最左的端点，使得代价靠近 m
取最大值即可。
*/
#include <bits/stdc++.h>
using namespace std;

const int N=5e5+10;
int n,nn,ans;
long long m,a[N],num,now;

/*int f(int dis){
	int k=upper_bound(a+1,a+n+1,dis)-a-1;
	int res=0;long long need=0;
	for(int i=k;i>=1;i--){
		need+=dis-a[i];
		if(need<=m) res++;
		else break;
	}
	return res;
}*/


int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;now=n+1;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		while(now>1&&num+a[i]-a[now-1]<=m) now--,nn++,num+=a[i]-a[now];
		ans=max(ans,nn);
		nn--;
		num-=nn*(a[i]-a[i-1]);
	}
	cout<<ans<<endl;
	return 0;
}
