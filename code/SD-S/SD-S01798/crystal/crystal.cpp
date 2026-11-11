#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5;
long long a[N],next[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m,sum=0,maxn=-1;
	cin>>n>>m;
	for(long long i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+1+n);
	//for(long long i=1;i<=n;i++)cout<<a[i]<<' ';
	for(int i=1;i<=n;i++){
		next[i]=a[i]-a[i-1];
	}
	long long l=1,r=1;
	while(l<=r&&r<=n){
		if((r-l)*next[r]+sum<=m){
			//cout<<l<<' '<<r<<' '<<r-l+1<<' '<<sum<<endl;
			sum+=(r-l)*next[r];
			maxn=max(maxn,r-l+1);
			r++;
		}
		else {
			sum-=a[r-1]-a[l];
			l++;
		}
	}
	cout<<maxn;
	return 0;
} 
//freopen别注释；测试输出要删去；
//文件夹、文件名写对了吗；
//freopen输入输出文件名写对了吗 
//函数return了吗  ;long long;scanf
//T1总得满分吧 
