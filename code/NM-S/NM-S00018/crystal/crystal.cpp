#include<iostream>
#include<algorithm>
using namespace std;
long long n,m,a[500005],d[500005],ds[500005],dx[500005],maxc=-1,gs,t,l,r,mid,sum;

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	
	for(int i=1;i<=n;i++)d[i]=a[i]-a[i-1]+d[i-1];
	
	for(int i=2;i<=n;i++){//能量是用来补差的 
		sum=gs=0;
		t=i-1;//从当前往前方找，直到 前缀差大于能量m 
		while(t>=1){
			sum+=d[i]-d[t];
			if(sum>m)break;
			t--;
		}
		gs+=i-t;
		t=i;//往后找，看有没有相同的
		while(a[++t]==a[t-1]);
		gs+=t-i-1;
		i=t-1;
		maxc=max(maxc,gs); 
	}
	cout<<maxc;
	return 0;
}
/*
很奇怪啊 这道怎么贪心
大水晶是个什么东西，题目意思其实是：
 
每次操作为 给某颗水晶 能量+1
最后要拿到最多的能量相同的水晶

考虑前缀差的和 
退而求其次 写个n^2? 
我也不知道到底是n方还是nlogn
(笑) 
*/
