#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n;
int a[N];
long long b[N],s[N],d[N],m;

bool check(int len){
	long long minn=1e18;
	for(int i=1;i+len-1<=n;i++)
		minn=min(minn,b[i+len-2]-b[i-1]-s[i+len-2]*(len-1));
	return minn<=m;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)	cin>>a[i];
	sort(a+1,a+1+n);
	
	for(int i=1;i<n;i++)	s[i]=a[i+1]-a[i];
	for(int i=n-1;i>=1;i--)	s[i]+=s[i+1];
	for(int i=1;i<n;i++)	b[i]=b[i-1]+s[i];
	
	int l=0,r=n;
	while(l<r){//找最大值
		int mid=l+r+1>>1;
		if(check(mid))	l=mid;
		else			r=mid-1;
	}
	cout<<r-1;
	return 0;
}
/*
5 5
1 2 4 8 9

5 8
-3 -1 2 2 7
*/
/*
dp? x 5e5
贪心?

从第 i 个开始加到第 j 个
做前缀和，做两次前缀和
x ..不知道了 

二分?
 感觉应该是
尝试口糊一个代码 
 O(nlogn)
 pass!!! 
 
 
前缀和计算代价:

i与 i+1的差 
a1+s1=a2,a2+s2=s3;
a1+s1+s1=s3;
--
i 从 i合到 n  
b1=s1+s2+s3;
b3=s3;
b1-b3=s1+s2;
---
i~n 合起来的代价 
c3=b1+b2+b3,c1=b1; 
c3-c1=b2+b3=s2+s3+s3; pass"!"!"(划掉)

c2-c0=b1+b2=s1+s2+s3+s2+s3; wrong

重设 
应该依旧倒序处理？
c1=b1+b2+b3,c3=b3
c1-c3(从 1合到 2)=b1+b2=s1+s2+s3+s2+s3
 
错误
改为
c1-c3-s3*2 
 

*/