#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005],sm[500005];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)sm[i]=sm[i-1]+a[i];
	int as=0;
	for(int i=1;i<=n;i++){
		int l=1,r=n,ans=-1;
		while(l<=r){
			int mid=l+r>>1;
			if((a[i]*(i-mid+1)-(sm[i]-sm[mid-1]))<=m){
				ans=mid,r=mid-1;
			}else{
				l=mid+1;
			}
		}
		//cout<<i<<" "<<ans<<endl;
		if(ans!=-1)as=max(as,i-ans+1);
	}
	cout<<as<<endl;
	return 0;
}
