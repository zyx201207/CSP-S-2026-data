#include <bits/stdc++.h>
#define int long long
using namespace std;
int readint(){
	int k=0,f=1,c=getchar();
	for(;!isdigit(c);c=getchar()) if(c=='-')f=-1;
	for(;isdigit(c);c=getchar()) k=k*10+(c-'0');
	return f*k;
}
int a[550000],n,m,ans=0; 
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	int sum=0,l=1;
	for(int r=1;r<=n;r++){
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m){
			sum-=(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
	} 
	cout<<ans;
	return  0;
} 
