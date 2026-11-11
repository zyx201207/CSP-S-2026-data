#include <bits/stdc++.h> 
#define int long long
#define endl "\n"
using namespace std;
int n,m; 
struct P{
	int b,c;
}a[200005];
int pd(int x){
	int r=0;
	while(!x){
		if(x%2==1) r++;
		x/=2;
	} 
	return r;
}
bool cmp(P a,P b){
	if(a.c==b.c) return a.b>b.b;
	else return a.c>b.c;
}
signed main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	if(m==n){
		int ans=a[1].b;
		for(int i=1;i<=n;i++){
		cin>>a[i].b;
		ans&=a[i].b;
	}
	cout<<ans;
	return 0;
	}
	for(int i=1;i<=n;i++){
		cin>>a[i].b;
		a[i].c=pd(a[i].b);
	}
	sort(a+1,a+1+n,cmp);
	int ans=a[1].b;
	for(int i=1;i<=m;i++){
		ans&=a[i].b;
	}
	cout<<ans;
	return 0;
}
