#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[200100],maxx;
bool e[200100][33];
bool f(int x,int k){
	return x&(1<<k);
}
bool cmp(int u,int v){
	for(int i=31;i>=1;i--){
		if(f(u,i)!=f(v,i)){
			return f(u,i)>f(v,i);
		}
	}
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++){
		for(int j=1;j<=31;j++){
			e[i][j]=f(a[i],j);
		}
	}
	maxx=a[1];
	for(int i=2;i<=m;i++){
		maxx&=a[i];
	}
	cout<<maxx;
}