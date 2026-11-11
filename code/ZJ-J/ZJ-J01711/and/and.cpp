#include<bits/stdc++.h>
#define AKCSPJ ios::sync_with_stdio(false);cin.tie(0),cout.tie(0)
#define int long long
using namespace std;//55pts
int a[200010],f[500010],dis[500010];
bool check(int a){
	int t=a+1;
	while(t){
		if(t==1)	return true;
		t/=2;
	}
	return false;
}
signed main(){
	AKCSPJ;
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	
	int n,m;
	cin>>n>>m;
	int mx=INT_MIN,l,flag_A=1;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(!check(a[i]))	flag_A=0;
		if(mx<a[i]){
			mx=a[i];
			l=i;
		}
	}
	if(flag_A){
		sort(a+1,a+n+1);
		cout<<a[n-m+1];
		return 0;
	}
//	cout<<l<<endl;
	f[1]=mx;
	dis[l]=1;
	for(int i=2;i<=m;i++){
		int final=0;
		for(int j=1;j<=n;j++){
			if(dis[j])	continue;
			if(f[i-1]&a[j]>=f[i]){
				f[i]=f[i-1]&a[j];
				final=j;
			}
		}
//		cout<<a[final]<<" ";
		dis[final]=1;
	}
	cout<<f[m];
	return 0;
}
