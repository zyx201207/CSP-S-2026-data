#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int a[N],n,m,f[N],ans=1;

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}	
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		f[i]=a[i]+f[i-1];
	}
	for(int i=1,j=1;j<=n;){
		if(i==j){
			j++;
		}
		int x=a[j]*(j-i+1)-f[j]+f[i-1];
		if(x<=m){
			ans=max(j-i+1,ans);
			j++;
		}else{
			i++;
		}
	}
	cout<<ans<<endl;
	return 0;
} 
//实在想不到更快的算法了，直接小用一个双指针得了
//估计得爆 
