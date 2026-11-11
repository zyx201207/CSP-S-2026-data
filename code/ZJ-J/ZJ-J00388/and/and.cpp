#include<bits/stdc++.h>
using namespace std;
const int N=2e3+1;
int n,a[N],m,dp[N][N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	int mx=0,x,y;
	x=0,y=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		mx=max(mx,a[i]);
		if(i==1) x=a[i];
		x&=a[i];
	}
	if(m==1){
		cout<<mx;
		return 0;
	}
	if(m==n){
		cout<<x;
		return 0;
	}
	if(m==2){
		mx=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				mx=max(mx,a[i]&a[j]);
			}
		}
		cout<<mx;
		return 0;
	}
	if(m==n-1){
		mx=0;
		for(int i=1;i<=n;i++){
		y=0;
			for(int j=1;j<=n;j++){
				if(i==j) continue;
				if(y==0) y=1,x=a[j];
				else x&=a[j];
			}
			mx=max(x,mx);
		}
		cout<<mx;
		return 0;
	}
	return 0;
}