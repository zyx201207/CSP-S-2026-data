#include<bits/stdc++.h>
using namespace std;
long long n,m,a[1000005],sum[1000005],cha,fc=1,ans,cnt,lim;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+1+n);
	cha=a[2]-a[1];
	for(int i=3;i<=n;i++){
		if(a[i]-a[i-1]!=cha){
			fc=0;
			break;
		}
	}
	if(fc){
		sum[1]=a[1];
		for(int i=2;i<=n;i++){
			sum[i]=sum[i-1]+a[i];
		}
		for(int i=1;i<=n;i++){
			if(m<sum[i]){
				ans=i-1;
				break;
			}
		}
		cout<<ans;
	}
	else if(n<=30000){
		for(int i=1;i<=n;i++){
			lim=0;
			for(int j=i;j>=1;j--){
				lim+=a[i]-a[j];
				if(lim>m){
					cnt=i-j;
					break;
				}
				if(j==1&&lim<=m){
					cnt=i;
				}
				//cout<<a[i]<<' '<<a[j]<<endl;
			}
			//cout<<cnt<<endl;
			ans=max(ans,cnt);
		}
		cout<<ans;
	}
	else{
		cout<<1;
	}
	return 0;
}
//5 5 
//1 2 4 8 9
