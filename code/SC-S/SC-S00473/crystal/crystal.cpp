#include<bits/stdc++.h>
using namespace std;
long long a[500005],pre[500005];
long long n,m;
long long c(long long i){
	long long l=1,r=i,mid,an;
	while(l<=r){
		mid=(l+r)/2;
		long long sum=(i-mid)*a[i]-(pre[i-1]-pre[mid-1]);
		if(sum<=m){
			r=mid-1;
			an=mid;
		}else{
			l=mid+1;
		}
	}
	return an;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(long long i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	long long an=0;
	for(long long i=1;i<=n;i++){
		an=max(an,i-c(i)+1);
	}
	cout<<an;
	return 0;
}
//代码敲慢一点！！！
//注意freopen
//注意数组大小
//注意函数返回值
//注意取模


