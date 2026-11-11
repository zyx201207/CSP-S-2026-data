#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,l,r;
int a[500005],st[500005][25],pre_sum[500005],lg_2[500005];
void init(){
	for(int i=1;i<=n;i++){
		st[i][0]=a[i];
	    pre_sum[i]=pre_sum[i-1]+a[i];
	}
	for(int i=1;i<=20;i++){
		for(int j=1;j+(1<<i)-1<=n;j++){
			st[j][i]=max(st[j][i-1],st[j+(1<<(i-1))][i-1]);
		}
	}
	for(int i=1;i<=n;i++){
		lg_2[i]=log2(i);
	}
}
int qujian_max(int l,int r){
	int lg=lg_2[r-l+1];
	return max(st[l][lg],st[r-(1<<lg)+1][lg]);
}
int qujian_sum(int l,int r){
	return pre_sum[r]-pre_sum[l-1];
}
bool cheak(int len){
	bool ans=false;
	for(int l=1;l+len-1<=n;l++){
		int r=l+len-1;
		if(qujian_max(l,r)*len-qujian_sum(l,r)<=m){
			ans=true;
		}
	}
	return ans;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	init();
	l=1,r=n;
	while(l<r){
		int mid=(l+r+1)>>1;
		if(cheak(mid))l=mid;
		else r=mid-1;
	}
	cout<<l;
	return 0;
}
