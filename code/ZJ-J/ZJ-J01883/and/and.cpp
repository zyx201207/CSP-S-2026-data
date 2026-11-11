#include<bits/stdc++.h>
#define ll long long
#define ull unsigned long long
#define pii pair<int,int>
#define pb push_back
using namespace std;

const int N=2e5+10;

int n,m,a[N],dp[N];

void solve(){
	n=0;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	dp[0]=(1<<30)-1;
	for(int i=1;i<=n;i++){
		for(int j=min(i,m);j>=1;j--){
			dp[j]=max(dp[j-1]&a[i],dp[j]);
		}
	}
	cout<<dp[m]<<endl;
	return;
}

int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	//for(int i=1;i<=30;i++)cout<<(1<<i)-1<<endl;
	solve();

	return 0;
}

