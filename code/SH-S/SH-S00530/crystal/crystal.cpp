#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+10;
int n,m,a[N];
int sum[N];
int ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
//	ios::sync_with_stdio(0);
//	cin.tie(0);
//	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);//排序 
	for(int i=1;i<=n;i++)sum[i]=sum[i-1]+a[i];//前缀和 
	for(int R=1;R<=n;R++){//枚举右端点 
		int fL,fR=R*a[R]-sum[R]-m;
		int l=1,r=R,mid,res=0;//二分左端点
		while(l<=r){
			mid=(l+r)>>1;
			fL=(mid-1)*a[R]-sum[mid-1];
			if(fL>=fR){//可行，保存答案，并考虑能否继续往前推 
				res=R-mid+1;
				r=mid-1;
			} 
			else{//不可行，往后推 
				l=mid+1;
			}
		} 
		ans=max(ans,res);//更新答案 
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
/*
从小到大排序a
求出前缀和sum
遍历右端点，寻找最小的左端点，使得区间尽可能大
固定R的情况下，将区间[L,R]内所有的数都变成a[R]
即d=a[R]*(R-L+1)-(sum[R]-sum[L-1])<=m
移项：R*a[R]-sum[R]-m<=(L-1)*a[R]-sum[L-1]
即证明右边单调递增即可
考虑f(L-1)=(L-1)*a[R]-sum[L-1]和f(L)=L*a[R]-sum[L]的大小
f(L)-f(L-1)=a[R]-sum[L]+sum[L-1]=a[R]-a[L]
由于a已经升序排序，故a[R]>=a[L]
因此f(L)>=f(L-1)，不等号右侧单调递增
有了单调性，便可以通过二分求解得到最小的L 
*/
