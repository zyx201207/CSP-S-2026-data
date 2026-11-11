#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m;
int a[N];
int q[N];
bool check(int x){ // O(n^2)
	for(int i=x;i<=n;i++){
		int cnt=0;
//		for(int j=i;j>=i-x+1;j--){
//			cnt+=a[i]-a[j]; //[16:45] 这里用前缀和优化？ 
//		}
        //cnt=x*a[i]-a[i]-a[i-1]-...-a[i-x+1] 
		cnt=x*a[i]-(q[i]-q[i-x]);
		if(cnt<=m) return true;
	}
	return false;
}
signed main(void){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
	}
	int L=1,R=n;
	while(L<R){
		int mid=(L+R)/2;
		if(check(mid)){
			L=mid+1;
		}else{
			R=mid;
		}
//		cout<<mid<<endl;
	}
//	for(int i=1;i<=n;i++){
//		cout<<q[i]<<endl;
//	}
	cout<<R-1;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
//T1 : Y3110W+/GR33N
//[15:30] 模拟走不通，有其他方法吗。。 
//[16:00] 居然是个二分答案？！ 
//[16:40] ...第一道题卡了两个小时了。。。还是只能拿到O(n^2 logn)的 复杂度。。 优化check函数ing... 
//[16:55] 成功把复杂度降到O(nlogn),测样例ing... 
//[17:02] 前三个样例没问题，第四个答案差一。。。。。。 
//[17:08] 终于过了。。。 累死了 T2,3 卡个特殊情况吧:P 
