#include<bits/stdc++.h>
using namespace std;
int a[200005];
int f[200005][100];
int maxn=-1e9;
int n,m;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out ","w",stdout);
	
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int maxn=-1e9;
	int ans=a[1];
	if(m==n){
		for(int i=2;i<=n;i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}
	if(m==1){
		for(int i=1;i<=n;i++){
			maxn=max(a[i],maxn);
		}
		cout<<maxn;
		return 0;
	}
	sort(a+1,a+1+n);
	if(m==2){
		for(int i=1;i<=n-1;i++){
			maxn=max(maxn,a[i]&a[i+1]);}
		cout<<maxn;
		return 0;
	}
	return 0;
	}
	
	


