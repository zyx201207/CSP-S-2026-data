#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],sub[500005],sum[500005];
int ma;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) sub[i]=a[i+1]-a[i];
	sub[n]=0;
	sum[1]=0;
	for(int i=2;i<=n;i++) sum[i]=sum[i-1]+sub[i-1]*(i-1);
//	for(int i=1;i<=n;i++) cout<<sum[i]<<' ';
//	cout<<endl;
	if(n<=10000){
		for(int i=1;i<n;i++){
			for(int j=i+1;j<=n;j++){
				if(sum[j]-sum[i]<=m) ma=max(ma,j-i+1);
			}
		}
	}
	else{
		for(int i=1;i<=n;i++){
			if(sum[i]>m){
				ma=i-1;
				break;
			}
		}
	}
	cout<<ma;
	return 0;
}
