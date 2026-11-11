#include<bits/stdc++.h>
using namespace std;
#define int long long
#define endl '\n'
int const N=2e5+10;
int n,m,a[N],maxx=-1e9;
bool cmp(int a,int b){
	return a>b;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	} 
	if(m==1) cout<<maxx;
	else if(m==n){
		int ans=a[1];
		for (int i=2;i<=n;i++) ans&=a[i];
		cout<<ans;
	}
	else if(m==2){
		int ans=-1e9;
		for (int i=1;i<=n;i++)
			for (int j=i+1;j<=n;j++)
				ans=max(ans,a[i]&a[j]);
		cout<<ans;
	}
	else{
		sort(a+1,a+n+1,cmp);
		int ans=a[1];
		for (int i=2;i<=m;i++) ans&=a[i];
		cout<<ans;
	}
	return 0;
}

