#include<bits/stdc++.h>
using namespace std;
using ll=long long;
const int maxn=2e5+10;
int a[maxn];
int aa[maxn];
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1,cmp);
	ll ma=0;
	ll ans;
	for(int i=1;i<=n-m+1;i++){
		ans=a[i];
		for(int j=i;j<=i+m-1;j++){
			ans&=a[j];
		}
		ma=max(ma,ans);
	}
	cout<<ma;
	return 0;
}