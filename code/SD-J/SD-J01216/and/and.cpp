#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
#define int long long
#define endl '\n'
#define ll long long

int a[200005];

bool cmp(int a,int b){
	return a>b;
}

signed main(){
	
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0); cout.tie(0);
	
	int n,m; cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	
	if(m==n){
		int ans=a[1];
		for(int i=2;i<=n;i++)
			ans&=a[i];
		cout<<ans;
		return 0;
		
	}else if(m==1){
		int ans=0;
		for(int i=1;i<=n;i++)
			ans=max(ans,a[i]);
		cout<<ans;
		return 0;
	}
	
	sort(a+1,a+n+1,cmp);
	
	int ans=a[1];
	for(int i=2;i<=m;i++)
		ans&=a[i];
		
	cout<<ans;
	 
	return 0;
}
