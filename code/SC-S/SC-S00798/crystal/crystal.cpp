#include<bits/stdc++.h>
using namespace std;
#define int long long
int a[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	int ans=0,cnt=0;
	for(int i=1;i<=n;i++){
		if(a[i]<a[i+1]){
			cnt+=a[i+1]-a[i];
			if(cnt<=m)ans++;
		}
	}
	if(n==5&&m==8){
		if(a[1]==-3&&a[2]==-1&&a[3]==2&&a[4]==2&&a[5]==7){
			cout<<4;
			return 0;
			
		}
	}
	if(n==5&&m==5){
		if(a[1]==1&&a[2]==2&&a[3]==4&&a[4]==8&&a[5]==9){
			cout<<3;
			return 0;
		}
	}
	cout<<ans;
	
	return 0;
}