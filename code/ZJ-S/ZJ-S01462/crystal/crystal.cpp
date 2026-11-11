#include<bits/stdc++.h>
#define int long long

using namespace std;

const int N=1e6+10;

int n,m,A[N],ans=1;
int qzh[N];

bool check(int x){
	bool flag=0;
	for(int i=1;i<=n;i++){
		if(i+x>n) break;
		if(x*A[i+x-1]-(qzh[i+x-1]-qzh[i-1])<=m) flag=1;
		if(flag==1) break;
	}
	return flag;
}

signed main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>A[i];
	sort(A+1,A+1+n);
	for(int i=1;i<=n;i++) qzh[i]=qzh[i-1]+A[i];
	int L=0,R=n,mid;
	while(L<=R){
		mid=L+R>>1;
		if(check(mid)){
			ans=mid;
			L=mid+1;
		}else R=mid-1;
	}
	cout<<ans<<"\n";
	return 0;
}
/*
把水晶排序了
然后用二分+前缀和做
前缀和是看操作多少次
二分是当前区间为合并区间是否满足
O(n)检查 
5 5
1 2 4 8 9 

5 8
-3 -1 2 2 7

*/
