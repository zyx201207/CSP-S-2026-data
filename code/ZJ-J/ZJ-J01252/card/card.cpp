#include<bits/stdc++.h>
using namespace std;
#define ll long long
const int N=500010,M=300010;
ll n,m;
ll a[N];
bool dp[N][M];
bool check1(){
	for(int i=1;i<=n;i++){
		if(a[i]>a[i+1])return 0;
	}
	return 1;
}
void solve1(){
	int ans[M]={0};
	for(int i=1;i<=n;i++){
		if(a[i]==a[i+1])ans[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		cout<<ans[i]<<' ';
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];	
	}
	if(check1()){
		solve1();
		return 0;
	}
	return 0;
}