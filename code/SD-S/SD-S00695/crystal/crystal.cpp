//Oct31==Dec25?
#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e6+10;
int n,a[N];
int m;
int d[N],sum_d[N];
int ans=-2;
bool flagone=1,flagtwo=1;
signed main(){
	//*&***********************************************************************
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	//cout<<1<endl;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(i>1&&a[i]!=i) flagone=0;
		if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]) flagtwo=0; 
	}
	if(flagtwo) {
		int i=a[2]-a[1];
		int j=0;
		int ans1=0;
		while(m>=0){
			j+=i;
			m-=j;
			ans1++;
		}
		cout<<ans1;
		return 0;
	}
	if(flagone){
		int i=0;
		while(m>=0){
			i++;
			m-=i;
		}
		cout<<i;
		return 0;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[i]=a[n]-a[i];
		for(int j=1;j<i;j++){
			sum_d[i]+=a[i]-a[j];
		}
	}
	//cout<<sum_d[10]<<" "<<sum_d[2]<<endl;
	//cout<<sum_d[5]-(d[]-d[5])
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			if(sum_d[j]-(d[i]-d[j])<=m||(i==1&&sum_d[j]<=m)){
				
				ans=max(ans,j-i);
				if(i==1&&sum_d[j]<=m){
					//cout<<1;
					ans=max(ans,j);
					continue;
				}
				//cout<<ans<<" "<<sum_d[j]<<" "<<j<<" "<<sum_d[i]<<" "<<i<<endl;
			}
		}
	}
	cout<<ans;
	return 0;
}
