#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e5+10;
int n,m,a[N],ma=0,len,ans,q[35][N];
void solve(){
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	if(m==1){
		for(int i=1;i<=n;i++)ma=max(ma,a[i]);
		cout<<ma;
		return;
	}
	else if(m==2){
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++){
				if(i==j)continue;
				int k=a[i]&a[j];
				ma=max(ma,k);
			}
		cout<<ma;
		return;
	}
	else{
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return;
	}
} 
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int te=1;
//	cin>>te;
	while(te--){
		solve();
	}
	return 0;
}
