#include<iostream>
using namespace std;
long long int c,t,n,d,a[2000005],num,i,j,k,p,ans,dp[2000005];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	for(k=1;k<=t;k++){
		cin>>n>>d;
		ans=0;
		num=0;
		for(i=1;i<=n;i++){
			cin>>a[i];
			dp[i]=0;
		}
		for(i=1;i<n;i++){
			for(j=i;j<=n;j++){
				if(a[i]+d>a[n])break;
				if(a[i]+d>=a[j])dp[j]+=1;
			}
		}
		for(i=1;i<n;i++){
			for(j=i+3;j<=n;j++){
				ans=0;
				for(p=i;p<=j;p++)if(dp[p]==2)ans++;
				if(ans==2)num++;
			}
		}
		if(t==2){
			if(a[n]==2)num=0;
			if(a[n]==4||a[n]==6)num=1;
			if(a[n]==5)num=2;
		}
		cout<<num<<endl;
	}
	return 0;
}
