#include<bits/stdc++.h>
using namespace std;
#define int long long
int n , m , a[500005] , s[500005] , ans=1 ;//至少有一个“大水晶”
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+1+n);
	// for(int i=1;i<=n;i++)s[i]=a[n]-a[i];
	// for(int i=1;i<=n;i++)s[i]=s[i]+s[i-1]/*,cout << s[i] << " "*/;
		// cout << "\n" ;
	for(int i=1;i<=n;i++)s[i]=a[i]+s[i-1];
	for(int i=1;i<=n;i++){//对于每个“水晶”，枚举该“水晶”作为最大的能量值
		//可以证明无需寻找不属于能量值数组里的其他基准值
		//下面将进行二分查找操作，寻找以第i个“水晶”为基准的情况下，[1,i]中最小符合条件的下标
		int l=1 , r=i , reans=i , mid ;
		// cout << i << "!!!\n" ;
		while(l<=r){
			// cout << l << " " << r << "\n" ;
			mid=l+(r-l)/2;
			if(a[i]*(i-mid)-s[i-1]+s[mid-1]<=m)reans=mid,r=mid-1;
			// if(s[i]-s[mid-1]-(i-mid+1)*(a[n]-a[i])<=m)reans=mid,r=mid-1;
			else l=mid+1;//,cout << a[i] << (i-mid) << s[i-1]-s[mid-1] << " ";
		}
		// cout << reans << "*\n" ;
		ans=max(ans,i-reans+1);
		// cout << "\n" ;
	}
	printf("%lld",ans);
	return 0;
}