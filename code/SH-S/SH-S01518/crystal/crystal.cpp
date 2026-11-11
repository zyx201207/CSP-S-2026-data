#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m;
int ans;
ll a[500005];
ll h[500005];//j个开始全部并到当前这个数的消耗m 
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	//a[0]=0
	//for(int i=n;i>=1;i--){
	//	a[i]-=a[i-1];
	//}
	for(int i=2;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			h[j]=h[j+1]+a[i]-a[j];
			//cout<<j<<"  "<<h[j]<<endl;
			if(h[j]>m){
		    	ans=max(i-j,ans);
		    	//cout<<"ans="<<ans<<endl;
		    	break;
			}
			if(j==1){
				ans=max(i-j+1,ans);
		    	//cout<<"ans="<<ans<<endl;
		    	break;
			}
		}
	}
	cout<<ans;
	return 0;
} 
