#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+10;
long long a[N],s[N],d[N],ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		s[i]=s[i-1]+(a[n]-a[i]);
	}
	for(long long i=n;i>=1;i--){
		d[i]=d[i+1]+(a[n]-a[i]);
	}
	for(long long r=1;r<=n;r++){
		long long ll=1,rr=r,mid,anss;
		while(ll<rr){
			mid=(ll+rr)>>1;
			anss=s[n]-s[mid-1]-d[r+1]-(r-mid+1)*(a[n]-a[r]);
			if(anss>m) ll=mid+1;
			else rr=mid;
		}
		ans=max(ans,r-ll+1);
	}
	cout<<ans;
	return 0;
}
//T1 crystal
//75pts 的暴力我已经非常满意了
//但做为老贪家我还是准备去写正解
//噢不不不我发现了什么！！！100pts做法
//用s作为(a[n]-a[i])的前缀和，用d作为(a[n]-a[i])的后缀和
//则区间[l..r]的答案为s[n]-s[l-1]-d[r+1]-(r-l+1)*(a[n]-a[r]) 
//有了这个公式我们就可以在暴力的基础下使用二分优化
//时间O(n log n) 
//3:58 AC
//不行了 脸都快笑烂了
//期望100pts 