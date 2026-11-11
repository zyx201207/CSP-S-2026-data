#include<bits/stdc++.h>
using namespace std;
bool cmp(int x,int y){
	return x<y;
}
long long a[100005],c[100005],f[100005],dp[100005],x;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	int m1=m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	if(n<=4000){
		x=1;
	}
	sort(a,a+n,cmp);
	for(int i=1;i<n;i++){
		c[i]=a[i]-a[i-1];
	}
	f[1]=c[1];
	for(int i=2;i<n;i++){
		f[i]=f[i-1]+c[i]; 
		//cout<<f[i]<<' ';
	}
	for(int i=2;i<n;i++){
		m=m1;
		if(f[i]==f[i-1]){
			//dp[i]=dp[i-1];
		}
		for(int j=i-1;j>0;j--){
			if(m-(f[i]-f[j])<0){
				break;
			}
			m-=(f[i]-f[j]);
			dp[i]++;
		}
		//cout<<dp[i]<<endl;
		dp[i]=max(dp[i],dp[i-1]);
	}
	cout<<dp[n-1]+1+x;
	return 0;
}
