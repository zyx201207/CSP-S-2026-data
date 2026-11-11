#include<bits/stdc++.h>
#define priority_queue prq
using namespace std;
const int N=2e5+10;
int n,m;
int a[N];
int sum[40];
int ans;
int dp;
long long qp(int a,int b){
	long long ans=1;
	while(b){
		if(b&1) ans*=a;
		b/=2;a=a*a;
	}
	return ans;
}
bool cmp(int x,int y){
	return (x>>dp)&1<(y>>dp)&1;
}
bool cmp2(int x,int y){
	return (x>>dp)&1>(y>>dp)&1;
}
long long solve(int x,int n){
	if(x<0) return 0;
	for(int j=1;j<=n;j++){
		if((a[j]>>x)&1){
			sum[x]++;	
		}
	}
	if(sum[x]>=m){
		dp=x-1;sort(a+1,a+n+1,cmp);
		return qp(2,x)+solve(x-1,sum[x]);
	}else return 0+solve(x-1,n);
	
}
long long Solve(int x,int n){
	if(x<0) return 0;
	for(int j=1;j<=n;j++){
		if((a[j]>>x)&1){
			sum[x]++;	
		}
	}
	if(sum[x]>=m){
		dp=x-1;sort(a+1,a+n+1,cmp2);
		return qp(2,x)+Solve(x-1,sum[x]);
	}else return 0+Solve(x-1,n);
	
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	bool flag=true; 
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]!=i-1) flag=false;
	} 
	if(flag) cout<<Solve(30,n);
	else cout<<solve(30,n);
	return 0;
}

