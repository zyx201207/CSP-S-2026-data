#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,m,mx;
int a[500001],c[500001];
bool check(int x,int it){
	if(a[it]*(it-x+1)-(c[it]-c[x-1])<=m)return true;
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%lld %lld",&n,&m);
	for(int i=1;i<=n;i++)scanf("%lld",&a[i]);
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)c[i]=c[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int L=1,R=i,ans=0;
		while(L<=R){
			int mid=L+R>>1;
			if(check(mid,i)){
				ans=i-mid+1;
				R=mid-1;
			}
			else L=mid+1;
		}
		mx=max(mx,ans);
	}
	printf("%lld",mx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}