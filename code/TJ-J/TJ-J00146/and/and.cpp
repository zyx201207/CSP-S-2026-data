#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[200005];
bool cmp(int x,int y){
	return x>y;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	if(m==1){
		cout<<a[1];
	}
	else if(m==2){
		int maxn=0;
		for(int i=2;i<=n;i++){
			maxn=max(maxn,a[1]&a[i]);
		}
		cout<<maxn;
	}
	else{
	
		int ans=a[1];
		for(int i=2;i<=m;i++){
			ans=(ans & a[i]);
		}
		cout<<ans;}
	
	return 0;
} 
