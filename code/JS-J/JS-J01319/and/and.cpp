#include<bits/stdc++.h>
using namespace std;
int n,m,ma;
int a[100005];
int dp[100005];
bool ismz1(int x){
	for(int i=1;;i*=2){
		if(i-x==1){
			return 1;
		}
		else{
			return 0;
		}
	}
}
void dfs(int d,int x){
	if(d==m){
		int l=-1;
		for(int i=0;i<n;i++){
			if(l==-1&&dp[i]!=0)
			l=a[i];
			if(dp[i]!=0)
			l=l&(a[i]*dp[i]);
		}
		ma=max(ma,l);
		return ;
	}
	for(int i=x;i<n;i++){
		dp[i]=1;
		dfs(d+1,i+1);
		dp[i]=0;
	}
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	ma=0;
	int t=0,e=0,o=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		t+=(a[i]==3);
		e+=(a[i]==2);
		o+=(a[i]==1);
		ma=max(ma,a[i]);
	}
	if(ma<4){
		if(t<m){
			if(t+e>m){
				cout<<2;
			}
			else if(t+o>m){
				cout<<1;
			}
			else{
				cout<<0;
			}
		}
		else{
			cout<<3;
		}
		return 0;
	}
	sort(a,a+n);
	if(m==1){
		cout<<a[n-1];
		return 0;
	}
	if(m==n){
		int l=a[0];
		for(int i=0;i<n;i++){
			l=l&a[i];
		}
		cout<<l;
		return 0;
	}
	if(m==n-1){
		int l=a[1];
		for(int i=1;i<n;i++){
			l=l&a[i];
		}
		cout<<l;
		return 0;
	}
	if(m==2){
		for(int i=n-1;i>=0;i--){
			if(ismz1(a[i])){
				cout<<a[i-1];
				return 0;
			}
		}
	}
	ma=0;
	dfs(0,0);
	cout<<ma;
	return 0;
}
