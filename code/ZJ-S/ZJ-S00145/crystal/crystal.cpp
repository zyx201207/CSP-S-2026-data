#include<bits/stdc++.h>
#define int long long
using namespace std;
const int MAXN=500010;
int n,m,ans,a[MAXN],s[MAXN];
int calc(int i,int j){
	int mul=a[i]*(i-j+1);
	int sum=s[i]-s[j-1];
	return mul-sum;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=1;
	for(int i=1;i<=n;i++){
		int j=i-ans+1;
		while(j>1&&calc(i,j-1)<=m)j--,ans++;
	}
	cout<<ans;
	return 0;
}
