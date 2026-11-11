#include<bits/stdc++.h>
using namespace std;
int c,t,n,N,num=0;	
long long d,x[2000005],y[2000005];
int dp[2000005];
int lj(int i,int j){
		if(y[i]-y[j]<d){
			return 1;
		}
		return lj(i-1,j)+lj(i-2,j);
	
}
void mig(){
	cin>>n>>d;
	num=0;
	for(int i=1;i<=n;i++){
		cin>>x[i];
		y[i]=x[i]-x[1];
		
	}
	for(int i=1;i<=n;i++){
		for(int j=n;j>=0;j++)
			if(lj(i,j)==lj(j,i)) num++;
		
	}
	cout<<num;
	
	
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		mig();
	}
	return 0;
}