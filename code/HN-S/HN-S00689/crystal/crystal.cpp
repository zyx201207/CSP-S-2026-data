#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5*1e5+5;
int n,m,a[N],cnt,ans=1,s[N];//前缀和尝试优化 
int find(int x){//x表示当前的数位置，y表示当前cnt 
	int l=1,r=x,tag=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(a[x]*(x-mid)-(s[x]-s[mid-1])<m) r=mid-1;
		else l=mid+1;
	} 
	return l==1?x-l+1:x-l;
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	cnt=m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i]; 
	}	
	for(int i=1;i<=n;i++){
		if(a[i+1]==a[i]) continue;//每次选择相同数的尾端 
		ans=max(ans,find(i));
	}
	cout<<ans<<"\n";
	return 0;
} 
