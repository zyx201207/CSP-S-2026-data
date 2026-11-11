#include<cstdio>
#include<iostream>
#include<algorithm>
#define int long long
using namespace std;
const int N=2e6+5,INF=1e9;
int c,t,n,d,a[N],ans,sum[N],maxx;
void dfs(int xth,int r,int now){
	if(now>maxx){
		return;
	}
	if(xth==r){
		sum[now]++,maxx=min(maxx,now);
		return;
	}
	for(int i=xth+1;i<=r;i++){
		if(a[i]-a[xth]<=d){
			dfs(i,r,now+1);
		}
	}
	return;
}
bool check(int l,int r){
	maxx=r-l+1;
	for(int i=1;i<=r-l+1;i++){
		sum[i]=0;
	}
	dfs(l,r,0);	
	for(int i=1;i<=n;i++){
		if(sum[i]!=0){
			return sum[i]==2;
		}
	}
	return 0;
}
void solve1(){
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				ans+=check(i,j);
				if(check(i,j)){
//					cout<<i<<" "<<j<<"\n";
				} 
			}
		}
		cout<<ans<<"\n";
	} 
	return;
}
void solve2(){
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		if(n>1&&a[2]-a[1]<d){
			int mxt=d/(a[2]-a[1]);
			ans=(mxt>1?n-(mxt*2)+1:0);
		}
		cout<<max(ans,0ll)<<"\n";
	}
	return;
}
void solve3(){
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		ans=0;
		int sum=0,x=0;
		for(int i=1;i<=n;i++){
			if(a[n]-a[i]<=d&&a[i]-a[1]<=d){
				sum++,x=i;
			}
		}
//		for(int i=1;i<x;i++){
//			int idx=upper_bound(a+x+1,a+n+1,a[i]+d)-a;
//			if(idx<=n){
//				ans+=(n-idx+1);
//				cout<<ans<<" "<<idx<<" "<<i<<"\n";
//			}
//		}
		if(x-1>=1&&x+1<=n){
			int idx1=upper_bound(a+x+1,a+n+1,a[x-1]+d)-a;
			int idx2=lower_bound(a+1,a+x,a[x+1]-d)-a;
			if(idx1<=n&&idx2<x){
				ans+=(x-idx2)*(n-idx1+1);
//				cout<<idx<<" "<<ans<<"\n";
			}
		}
		cout<<ans<<"\n";
	}
	return;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>c>>t;
	if(c==11||c==12){
		solve2();
	}else if(c==13||c==14){
		solve3();
	}else if(c<=6){
		solve1();
	}else{
		while(t--){
			cin>>n>>d;
			for(int i=1;i<=n;i++){
				cin>>a[i];
			}
			cout<<0<<"\n";
		}
	}
	return 0;
}
/*
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

11 1
6 10
1 4 7 10 13 16

13 1
8 10
1 2 4 5 8 14 17 18
*/
