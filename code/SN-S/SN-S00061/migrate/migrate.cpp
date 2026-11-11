#include<bits/stdc++.h>
using namespace std;
int c,t,n,d,dp[5005][5005],x[5005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(int tt=1;tt<=t;tt++){
		cin>>n>>d;
		for(int j=1;j<=n;j++){
			cin>>x[j];
		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				int ds=x[j]-x[i],mina=ceil(ds*0.1/d;
				for(int k=i;i<=j;k++){
					if(x[k]-x[i]>d){
					
					}
				}
			}
		}
	}
	return 0;
} 
