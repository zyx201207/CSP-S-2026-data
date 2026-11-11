#include<bits/stdc++.h>
using namespace std;
int c,t,n,ans;
long long d,x[2000005],dp[2000005],l[2000005];

bool theA(){
	for(int i=3;i<=n;i++){
		if(x[i]-x[i-1]!=x[i-1]-x[i-2])return false;
	}
	return true;
}
int theB(){
	int xx=x[1]+d;
	int yy=x[n]-d;
	if(xx<yy)return false;
	for(int i=d;i<=n;i++){
		if(x[i]>=yy&&x[i]<=xx)return i;
	}
	return -1;
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		if(x[1]+d>=x[n]){
			cout<<0<<endl;
			continue;
		}
		if(theA()){
			d/=x[2]-x[1];
			if(d==1)cout<<0<<endl;
			else if(d==2)cout<<n-3<<endl;
			else if(d==3)cout<<(n-5)*(n-5)/2/2<<endl;
			else cout<<n-d*2+1<<endl;
			continue;
		}
		int zz=theB();
		if(zz>0){
			int yy=x[n]-d;
			for(int i=n;i>=1;i--){
				if(x[1]+d>=x[i]){
					yy=i;
					break;
				}
			}
			if(yy-zz+1==2){
				for(int i=1;i<zz;i++){
					for(int j=yy+1;j<=n;j++){
						if(x[i]+d<x[j])ans++;
					}
				}
				cout<<ans<<endl;
			}else cout<<0<<endl;
			continue;
		}
		for(int k=1;k<=n;k++){
			memset(dp,0,sizeof(dp));
			memset(l,0,sizeof(l));
			dp[k]=1;
			for(int i=k+1;i<=n;i++){
				for(int j=i-1;j>=k;j--){
					if(dp[j]+d>=dp[i]){
						if(l[j]+1<l[i]){
							l[i]=l[j]+1;
							dp[i]=dp[j];
						}else if(l[j]+1==l[i]){
							dp[i]+=dp[j];
						}
					}
				}
				for(int j=1;j<=n;j++){
					if(dp[j]==2)ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}//Oct31==Dec25? 
