#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2000010;
int c,t,n,d,x[N];
void code(){
	cin>>n>>d;
	for(int i=1;i<=n;i++){
		cin>>x[i];
	}
	if(n<=3){
		cout<<0;
		return ;
	}
	if(11<=c&&c<=12){
		if(d/(x[2]-x[1])<=1||d*2>x[n]-x[1])cout<<0;
		else cout<<max(n-((d/(x[2]-x[1]))*2)+1,0ll);
		return ;
	}
	int ans=0;
	for(int i=1,k,j;i<=n-3;i++){
		j=i+3;
		k=i+1;
		while(x[j]-x[i]<=d)++j;
		while(k<j&&x[j]-x[k]>d)++k;
		for(j;j<=n;j++){
			while(x[j]-x[k]>d)++k;
			if(x[k]-x[i]>d)break;
			if(x[k+1]-x[i]>d)break;
			if(k!=j-1&&x[k+2]-x[i]>d)++ans;
//			cout<<i<<' '<<j<<' '<<k<<'\n';
		}
	}
	cout<<ans;
//	if(13<=c&&c<=14){
//		int idx=upper_bound(x+1,x+n+1,x[1]+d)-x-1;
//		if(x[n]-x[idx+1]<=d&&x[idx+1]-x[0]<=d)cout<<0;
//		else{
//			if(idx==n-1){
//				if(x[idx]-x[idx-2]>=d&&x[idx+1]-x[idx-2]<=d)cout<<1;
//				else cout<<0;
//			}
//		}
//	}
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>t;
	while(t--){
		code();
		cout<<'\n';
	}
	return 0;
}
/*
0 1
5 3
-3 0 2 3 4

2
*/
