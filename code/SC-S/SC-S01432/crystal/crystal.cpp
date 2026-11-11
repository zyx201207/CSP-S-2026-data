//40分钟 100% 
#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long s[1000010];
long long a[1000010];
long long l,r;
long long cnt=0;
long long mx=0;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	l=1;
	r=1;
	while(r<=n){
		cnt=a[r]*(r-l+1)-(s[r]-s[l-1]);
		//s[r]*(r-l+1) 所需值
		//s[r]-s[l-1]  已有值
		if(cnt<=m){
			//cout<<cnt<<" "<<l<<" "<<r<<endl;
			mx=max(mx,r-l+1);
			r++;
		}else{
			l++;
		}
	
	}
	cout<<mx; 
	return 0;
} 
/*
题意转化:可以对序列 a 增加 m 次,a序列中相等的数最大 
考虑贪心+前缀和+双指针 
先对 a 数组进行排序+预处理前缀和 
l,r,cnt 需要的次数 
对于每一个区间因其为升序，所以 r 位置的数即为标准
使用前缀和数组计算所要的次数
如果当前次数小于 m 记录当前的区间长度 r++
否则 l++
因为如果仍还有次数，则可再加1个数
否则，次数超出限额，减少一个次数
因为每一次遍历的时候l,r都会++
所以复杂的约为 O(n)
整体复杂度 O(nlogn+n) 500000*19+500000=10000000
5 8
-3 -1 2 2 7

5 5
1 2 4 8 9
*/