#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500010];
bool check(int x){
	int nwcst=0,tcst=a[x];
	for(int i=1;i<=x;i++){
		nwcst+=tcst-a[i];
	}
	if(nwcst<=m)return 1;
	for(int i=x+1;i<=n;i++){
		tcst=a[i];
		nwcst=0;
		for(int j=i-x+1;j<=i;j++){
			nwcst+=tcst-a[j];
		}
		if(nwcst<=m)return 1;
	}
	return 0;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	int maxn=-2e9;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxn=max(maxn,a[i]);
	} 
	sort(a+1,a+n+1);
	int l=0,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)>>1;
		if(check(mid)){
			ans=mid;
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}

