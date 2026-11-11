#include<bits/stdc++.h> 
using namespace std;
#define int long long
int a[500005];
int pre[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1]+a[i];
	}
	int aans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			//cout<<mid<<'\n';
			if(a[i]*(i-mid+1)-(pre[i]-pre[mid-1])>m){
				l=mid+1;
			}else{
				r=mid-1;
				ans=mid;
			}
		}
		//cout<<ans<<'\n';
		aans=max(aans,i-ans+1);
	}
	cout<<aans;
	return 0;
}
/*
5 5
1 2 4 8 9
*/
