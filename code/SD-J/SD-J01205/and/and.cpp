#include <bits/stdc++.h>
using namespace std;
const int M=2e5;
long long n,m,a[M+5],ans1=0;

void dfs(long long x,long long j,long long sum){//cout<<endl<<l<<" "<<r<<" "<<k<<endl;
	if (x==m){
		ans1=max(ans1,sum);
		return ;
	}
	for (int i=j+1;i<=n;i++){
		if (x==0)dfs(1,i,a[i]);
		else dfs(x+1,i,sum&a[i]);
	}
}

int main(){
	freopen("and.in","r",stdin);
	freopen("ans.out","w",stdout);
	cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	if(n<=20){
		dfs(0,0,0);
		cout<<ans1<<endl;
	}
	else if (n<=2000){
		if (m==1){
			long long ans=0;
			for (int i=1;i<=n;i++){
				ans=max(a[i],ans);
			}
			cout<<ans<<endl;
		}
		if (m==n){
			long long ans=a[1];
			for (int i=1;i<=n;i++){
				ans=(ans&a[i+1]);
			}
			cout<<ans<<endl;
		}
		if (m==2){
			long long ans=(a[1]&a[2]);
			for (int i=1;i<=n;i++){
				for (int j=i+1;j<=n;j++){
					ans=max(ans,(a[i]&a[j]));
				}
			}
			cout<<ans<<endl;
		}
	}
	else {
		long long ans1=a[1];
		bool ifm=true;
		for (int i=1;i<=n;i++){
			ans1=min(ans1,a[i]);
			if (a[i]>=4)ifm=false;
		}
		if (ifm){
			long long sum3=0,sum2=0,sum1=0,sum0=0;
			for (int i=1;i<=n;i++){
				if (a[i]==3)sum3++;
				if (a[i]==2)sum2++;
				if (a[i]==1)sum1++;
				if (a[i]==0)sum0++;
				
			}
			if (sum3>m)cout<<3<<endl;
			else if (sum2+sum3>m)cout<<2<<endl;
			else if (sum1+sum3>m)cout<<1<<endl;
			cout<<0<<endl;
		}
		else {
			sort(a+1,a+n+1);
			long long g=0;
			for (int i=n;i>=1;i--){
				g++;
				if (g==m){
					cout<<a[g]<<endl;
					return 0;
				}
			}
		}
	}
	return 0;
}
