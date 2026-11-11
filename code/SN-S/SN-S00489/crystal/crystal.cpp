//SN-S00489 郝天哲 铜川市耀州区耀州中学 
#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+1;
int a[N],n,m,t,x,cnt=1;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	t=a[2]-a[1];
	x=1;
	do{
		x+=++cnt;
	}while(m-x*t>=0&&cnt<n);
	cout<<cnt<<endl;
	return 0;
}
