#include<bits/stdc++.h>
using namespace std;
long long n,m,ans,g[500005];
long long sum[500005],ans1;
int special(){
	cin>>g[1]>>g[2];
	if(g[2]-g[1]==1){
		for(int i=1;i<=n;i++){
			g[i]=i;
			sum[i]=(i-1)*i/2;
			if(m>=sum[i-1]&&m<sum[i]){
				cout<<i-1;return 0;
			}
		}
		if(m>=sum[n])cout<<n;
	}
	else{
		long long c=g[2]-g[1];
		for(int i=3;i<=n;i++){
			g[i]=g[i-1]+c;
			sum[i]=(g[i]-g[1]+c)*(i-1)/2;
			if(m>=sum[i-1]&&m<sum[i]){
				cout<<i-1;return 0;
		}
	}
	if(m>=sum[n])cout<<n;
	}	
	return 0;
}
int mainn(){
	long long sum1[5005][5005];
	int m1=m;
	for(int i=1;i<=n;i++){
		cin>>g[i];
	}
	sort(g+1,g+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum1[i][j]=g[j]-g[i];
		}
	}
	for(int i=1;i<=n;i++){
		ans1=0;m=m1;
		for(int j=1;j<=i;j++)
		{
			m-=sum1[j][i];
			if(m<0)break;
			ans1++;
		}
		ans=max(ans1,ans);
	}
	cout<<ans;
	return 0;
} 
int mainnn(){
	long long sum1[1005][1005];
	int m1=m;
	for(int i=1;i<=n;i++){
		cin>>g[i];
	}
	sort(g+1,g+1+n);
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum1[i][j]=g[j]-g[i];
		}
	}
	for(int i=1;i<=n;i++){
		ans1=0;m=m1;
		for(int j=1;j<=i;j++)
		{
			m-=sum1[j][i];
			if(m<0)break;
			ans1++;
		}
		ans=max(ans1,ans);
	}
	cout<<ans;
	return 0;
} 
int main(){
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n>5000)special();
	else if(n<1000) mainnn();
	else mainn();
	return 0;
}
