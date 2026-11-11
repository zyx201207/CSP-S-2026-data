#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<string>
#include<algorithm>
#include<vector>
#define int long long
using namespace std;
const int MAXN=2e6+20;
int a[MAXN],sum[MAXN];
int n,D,minans,cnt=0;
void dfs(int nowisland,int nowst,int v){
//	cout<<nowisland<<'\n';
	if(nowisland==v){
		if(nowst<minans){
			cnt=1;
			minans=nowst;
	//		cout<<nowst<<'\n';
		}
		else if(nowst==minans)cnt++;
		return ;
	}
	int sm=0;
	for(int i=nowisland+1;i<=v;i++){
		sm=a[i]-a[nowisland];
		if(sm<=D){
	//		cout<<i<<" ";
			dfs(i,nowst+1,v);
		}
		else break;
	}
}
bool check(int u,int v){
	minans=1e18;cnt=0;
//	cout<<"!"<<u<<" "<<v<<'\n';
	dfs(u,0,v);
	if(cnt==2)return 1;
	return 0;
}
void solve(){
	int ans=0;
	cin>>n>>D;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		sum[i]=sum[i-1]+a[i];
	}
	for(int i=1;i<=n;i++)
		for(int j=i+1;j<=n;j++)
			if(check(i,j)){
			//	cout<<i<<" "<<j<<'\n';
				ans++;
			}
	cout<<ans<<'\n';
}
void solve0(){
	cin>>n>>D;
	int pos=0;
	for(int i=1;i<=n;i++)cin>>a[i];
	cout<<0<<'\n';
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,T;cin>>c>>T;
	while(T--){
		if(c==13||c==14)solve0();
		else solve();
	}
	return 0;
} 
/*
0 2
4 2
1 2 3 4
5 2
1 2 3 4 5


0 1
4 2
1 2 3 4

0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

*/
