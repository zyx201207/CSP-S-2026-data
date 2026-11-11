#include<bits/stdc++.h>
#define ll long long
#define N 500050
using namespace std;
ll a[N],qian[N];
int n;ll m;
int hefa(int l,int r){
	return a[r]*(r-l+1)-(qian[r]-qian[l-1])<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		qian[i]=qian[i-1]+a[i];
	}
	int l=n;
	int ans=0;
	for(int r=n;r>=1;r--){
		while(l>r)l--;
		while(l>1&&hefa(l-1,r))l--;
		ans=max(ans,r-l+1);
	}
	printf("%d\n",ans);
	return 0;
}
/*
5 5
1 2 4 8 9

3
*/
