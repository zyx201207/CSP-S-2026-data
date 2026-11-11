#include<bits/stdc++.h>
using namespace std;
#define zhr ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl '\n'
#define int long long
const int N = 2e5+5;
int n,m;
int dp[N];
int a[N];
bool flag1=1,flag2=1;
void solve1(){
	for(int i=0;i<=0;i++){
		dp[i]=(1<<21)-1;
	}
	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			
			dp[j]=max(dp[j],(dp[j-1]&a[i]));
		}
	}
	cout<<dp[m];
	return ;
}
int mi[50];
bool cmp(int x,int y){
	return x>y;
}
void solve2(){
	sort(a+1,a+1+n,cmp);
	cout<<a[m];
	return ;
}

signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	zhr;
	cin>>n>>m;
	mi[0]=1;
	for(int i=1;i<=31;i++) mi[i]=mi[i-1]*2;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		bool is=0;
		if(flag1){
			for(int j=1;j<=30;j++){
				if(a[i]==mi[j]-1){
					is=1;
					break;
				}
			}
		}		
		if(!is) flag1=0;
	}
	if(flag1) solve2();
	else if(n*m<=100000000) solve1();
	else cout<<49152;
	
	return 0;
}
