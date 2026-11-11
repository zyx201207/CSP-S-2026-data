#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10;
#define ll long long
int a[N];
int dp[N];
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ma=0;
	for(int i=1;i<=n;i++){
		ma=max(a[i],ma);
	}
	if(m==1){
		cout<<ma;
	}
	else if(m==n){
		int ans=a[1];
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}
	else if(m==2){
		int ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
		cout<<ans;
	}
	cout<<0;
	return 0;
}

