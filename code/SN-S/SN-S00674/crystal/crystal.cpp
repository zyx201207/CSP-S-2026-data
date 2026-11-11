#include<bits/stdc++.h>
#define ll long long
using namespace std;
namespace Vesperon{
	ll n,m,a[500005],sum=0,ans=0,mx=-LLONG_MAX,pre[500005];
	void work(){
		freopen("crystal.in","r",stdin);
		freopen("crystal.out","w",stdout);
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>a[i];
			//if(i>=2) pre[i]=pre[i-1]+(i-1)*(a[i]-a[i-1]);
		}
		sort(a+1,a+n+1);
		/*for(int i=1;i<=n;i++){
			for(int j=i;j>=1;j--){
				sum+=a[i]-a[j];
			}
			if(sum<=m&&sum>=mx){
				mx=sum;
				ans=i;
			}
			if(sum>m) break;
			sum=0;
		}*/
		for(int i=1;i<=n;i++){
			if(i>=2) pre[i]=pre[i-1]+(i-1)*(a[i]-a[i-1]);
		}
		for(int i=1;i<=n;i++){
			if(pre[i]<=m&&pre[i]>=mx){
				mx=pre[i];
				ans=i;
			}
		}
		cout<<ans;
	}
}
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	return Vesperon::work() ,0;
}
