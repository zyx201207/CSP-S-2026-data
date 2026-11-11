#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+10;
int a[N];
int ci=1;
int ans=0;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	if(n==1){
		cout<<1;
		return 0;
	}
	else if(n==2){
		if(a[2]-a[1]>m){
			cout<<1;
			return 0;
		}
		else{
			cout<<2;
			return 0;
		}	
	}
	else if(n==3){
		if(a[3]-a[2]+a[3]-a[1]<=m){
			cout<<3;
			return 0;
		}
		else if(a[3]-a[2]<=m||a[2]-a[1]<=m){
			cout<<2;
			return 0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	else if(n==4){
		if(a[4]-a[3]+a[4]-a[2]+a[4]-a[1]<=m){
			cout<<4;
			return 0;
		}
		else if(a[4]-a[3]+a[4]-a[2]<=m||a[3]-a[2]+a[3]-a[1]<=m){
			cout<<3;
			return 0;
		}
		else if(a[4]-a[3]<=m||a[3]-a[2]<=m||a[2]-a[1]<=m){
			cout<<2;
			return 0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	else if(n==5){
		if(a[5]-a[4]+a[5]-a[3]+a[5]-a[2]+a[5]-a[1]<=m){
			cout<<5;
			return 0;
		}
		else if(a[5]-a[4]+a[5]-a[3]+a[5]-a[2]<=m||a[4]-a[3]+a[4]-a[2]+a[4]-a[1]<=m){
			cout<<4;
			return 0;
		}
		else if(a[5]-a[4]+a[5]-a[3]<=m||a[4]-a[3]+a[4]-a[2]<=m||a[3]-a[2]+a[3]-a[1]<=m){
			cout<<3;
			return 0;
		}
		else if(a[5]-a[4]<=m||a[4]-a[3]<=m||a[3]-a[2]<=m||a[2]-a[1]<=m){
			cout<<2;
			return 0;
		}
		else{
			cout<<1;
			return 0;
		}
	}
	else{
		if(a[1]==a[2]){
		cout<<n;
		return 0;
		}
}
	for(int i=1;i<=n;i++){
		int cha=a[2]-a[1];
		ans+=cha*ci;
		if(ans>m){
			cout<<ci;
			return 0;
		}
		ci++;
	}
	cout<<ci-1;
	return 0;
}
