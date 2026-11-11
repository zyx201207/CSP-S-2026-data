#include<bits/stdc++.h>
using namespace std;
const long long N=5e5+5,M=1e18;
long long n,m,a[N],cf[N],precf[N],t[N],dp[N],ans,x,y,yj,mq;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}sort(a+1,a+n+1);
	cf[1]=0;
	precf[1]=0;
	for(int i=2;i<=n;i++){
		cf[i]=a[i]-a[i-1];
		precf[i]=cf[i]+cf[i-1];
	}
	for(int i=1;i<=n;i++){
		yj=0,mq=0;
		for(int j=i+1;j<=n;j++){
			if(yj+cf[j]*(mq+1)<=m){
				yj+=(mq+1)*cf[j];
				cout<<yj<<endl;
				mq++;
			}
			else break;
		}
		ans=max(ans,mq+1);
	}
	cout<<ans;
	return 0;
} 
