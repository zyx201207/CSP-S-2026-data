#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],ans,bm,maxx,f1=1;
bool cmp(int x,int y){
	return x>y;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	bm=m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		ans=1;
		m=bm;
		for(int j=i-1;j>=1;j--){
			if(m>=a[i]-a[j]) ans++,m-=(a[i]-a[j]);
		}
		maxx=max(maxx,ans);
	}
	cout<<maxx;
	return 0;
}