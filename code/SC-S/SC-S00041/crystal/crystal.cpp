#include<bits/stdc++.h>
using namespace std;
//思路：
//1,排序
//2，枚举数列中的每一项，以它为终点，向前依次操作，记录并更新答案
//这样会爆炸
//考虑优化：由于需要反复使用两数差的和
//即a[i]-a[i-1]+(a[i]-a[i-1]+a[i-1]-a[i-2])+...+(a[i]-a[i-1]+a[i-1]-a[i-2]+...+a[i-k+1]-a[i-k])
// =a[i]-a[i-1]+a[i]-a[i-2]+a[i]-a[i-3]+...+a[i]-a[i-k]
// =k*a[i]-(a[i-1]+...+a[i-k])
//因此可以使用前缀和与二分查找优化
//思考qz[i]=a[1]+...+a[i]
//那么可以表示为k*a[i]-qz[i-1]+qz[i-k-1];
//以1~i-1为区间二分查找k即可
//找到最大的k使得上式<=m; 
//__int128是个好东西 
__int128 qz[(int)5e5+10];  
long long n,m,a[(int)5e5+10]; 
bool js(int k,int num){
	__int128 s=k*a[num]-qz[num-1]+qz[num-k-1];
	return s<=m;
} 
int search(int l,int r){
	int num=r;
	while(l<r){
		int mid=(l+r)/2;
		if(js(mid,num))l=mid+1;
		else r=mid;
	}
	
	return l;
} 
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	freopen("crystal.in","r",stdin);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	
	sort(a+1,a+n+1);
	
	qz[0]=0;
	for(int i=1;i<=n;i++)qz[i]=qz[i-1]+a[i]; 
	
	long long res=1;
	for(int i=n;i>0;i--){
		long long ans=search(1,i);
		res=max(res,ans);
	}
	
	freopen("crystal.out","w",stdout);
	cout<<res;
	

	return 0;
}
