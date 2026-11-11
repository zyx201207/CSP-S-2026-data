#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,head=1,tail,ans;
int a[505050],sum[505050];
int maxn(int u,int v){
	return u>v?u:v;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		while((a[i]-a[i-1])*(i-head)>m&&head<i){
			m+=a[i-1]-a[head];
			head++;
		}
		m-=(a[i]-a[i-1])*(i-head);
		ans=maxn(ans,i-head+1);
	}
	cout<<ans;
	return 0;
}
