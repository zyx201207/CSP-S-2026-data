#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m;
int a[200005];
bool cmp(int a,int b){
	return a>b;
}
int maxx;
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","W",stdin);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		maxx=max(maxx,a[i]);
	}
	int ans=a[1];
	if(m==n){
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
	}
	else if(m==1){
		ans=maxx;
	}
	else if(m==2){
		ans=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				ans=max(ans,a[i]&a[j]);
			}
		}
	}
	else{
		ans=a[1];
		sort(a+1,a+n+1,cmp);
		for(int i=1;i<=m;i++){
			ans&=a[i];
		}
	}
	cout<<ans;
	return 0;
}
