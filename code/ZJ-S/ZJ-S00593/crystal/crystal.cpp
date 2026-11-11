#include<bits/stdc++.h>
using namespace std;
long long a[500004];
long long ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0) ;
	cin.tie(0);cout.tie(0);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	a[n+1]=1000000000000000000; 
	sort(a+1,a+1+n);
	for(int l=1;l<=n;l++){
		for(int r=l;r<=n;r++){
			int d=r-l+1;
		long long minn=0,sum=0;
		if(d%2==0){
			for(int i=l;i<=r;i++){
				if(a[(r-l)/2+l]-a[i]>=0)minn+=a[(r-l)/2+l]-a[i];
				else minn+=a[i]-a[(r-l)/2+l];
			}
			for(int i=l;i<=r;i++){
				if(a[(r-l)/2+l+1]>=a[i])sum+=a[(r-l)/2+l+1]-a[i];
				else sum+=a[i]-a[(r-l)/2+l+1];
			}
			minn=min(minn,sum);
		}
		else{
			for(int i=l;i<=r;i++){
				if(a[(r-l)/2+l]-a[i]>=0)minn+=a[(r-l)/2+l]-a[i];
				else minn+=a[i]-a[(r-l)/2+l];
			}
		}
//		cout<<l<<' '<<r<<' '<<minn<<endl;
		if(minn<=m){
			ans=max(ans,1LL*d);
		}
		}
	} 
		cout<<ans;
	
	return 0;
}
/*
16:02 25p
i am sad
ccf rp++ rp-- 
luogu User jfyjfy
*/
