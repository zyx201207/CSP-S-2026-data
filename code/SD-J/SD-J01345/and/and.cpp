#include<bits/stdc++.h>
using namespace std;
freopen("and.in","r",stdin)
freopen("and.out","w",stdout)
int n,m;
int sort;
struct P{
	int b,c;
}a[200005];
int pd(int x){
	int r=0;
	while(!x){
		if(x%2==1)r++;
		x/=2;
	}
	return r;
}
bool cmp(P a,P b){
	if(a.c==b.c)return a.b>b.b;
	else return a.c>b.c;
}
signed main(){
	int sort;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i].b;
		a[i].c=pd(a[i].b);
		sort(a+1,a+1+n,cmp);	
	}
		for(int i=2;i<=m;i++){ 
			ans&=a[i].b;
		}
	cout<<ans;	
	return 0;
}
