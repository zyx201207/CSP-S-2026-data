#include<bits/stdc++.h>
#define ull unsigned long long
using namespace std;
int n;
const int N=5e5+10;
ull a[N];
long long k[N];
ull p[N];
long long m;
long long ans=0;
bool cmp(ull x,ull y){
	return x<y;
}
long long mn=1e18;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
    freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>k[i];
		mn=min(k[i],mn);
	}
	for(int i=1;i<=n;i++){
		a[i]=k[i]-mn+1;
	}
	sort(a+1,a+1+n,cmp);
	for(int i=1;i<=n;i++) p[i]=p[i-1]+a[i];
	for(int i=1;i<=n;i++){
		ull sum=a[i]*(i-1)-p[i-1];
		if(sum<=m) ans=i;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
