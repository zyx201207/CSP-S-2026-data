#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],c[N],cnt[N],j=1,sum[N],len[N],ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	c[1]=a[1];
	cnt[1]++;
	for(int i=2;i<=n;i++){
		if(a[i]==c[j]){
			cnt[j]++;
			continue;
		}
		c[++j]=a[i];
		cnt[j]++;
	}
	for(int i=1;i<=j;i++){
		sum[i]=sum[i-1]+c[i]*cnt[i];
		len[i]=len[i-1]+cnt[i];
	}
	int l=1,r=2;
	ans=len[l];
	while(l<=r&&r<=j){
		int del=(len[r-1]-len[l-1])*c[r]-(sum[r-1]-sum[l-1]);
		if(del<=m){
			ans=max(ans,len[r]-len[l-1]);
			r++;
		}
		else{
			l++;
		}
	}
	cout<<ans;
	return 0;
}
