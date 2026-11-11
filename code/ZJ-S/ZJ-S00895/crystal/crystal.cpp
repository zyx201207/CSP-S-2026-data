#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[500001];
int s[500001];
int n,m,ans,cnt;
bool cmp(int a,int b){
	return a<b;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1,j=1;i<=n;i++){
		int lxm=a[i]*(i-j+1);
		while(j<=i&&lxm-s[i]+s[j-1]>m){
			j++;
			lxm-=a[i];
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}