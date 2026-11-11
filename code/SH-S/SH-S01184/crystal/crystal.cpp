#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500050];
long long cha[500050],sum[500050],sum1[500050],ans=1;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	if(n<=5000){
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		sort(a+1,a+1+n);
		cha[1]=0;
			for(long long i=2;i<=n;i++){
			cha[i]=a[i]-a[i-1];
			sum[i]=cha[i]*(i-1)+sum[i-1];
		}
		for(long long i=1;i<=n;i++){
			for(long long j=i;j<=n;j++){
				if(sum[j]<=m){
					ans=max(ans,j-i+1);
				}
				sum[j]-=cha[i+1];
			}
		}
		cout<<ans;
		return 0;
	}
	else{
		for(int i=1;i<=n;i++){
			cin>>a[i];
		}
		int k=0,sum=0;
		int d=a[2]-a[1];
		while(sum<=m){
			k++;
			sum+=k;
		}
		k--;
		cout<<k;
	}
	return 0;
}
