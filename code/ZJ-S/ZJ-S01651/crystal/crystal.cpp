#include<bits/stdc++.h>
using namespace std;
long long a[500001];
long long qzh[500001];
int main(){
//	freopen("crystal4.in","r",stdin);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	int ans=1;
	for(int i=1;i<=n;i++)
		qzh[i]=qzh[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l!=r){
			int mid=(l+r)>>1;
			if(qzh[i]-qzh[mid-1]+m>=a[i]*(i-mid+1))
				r=mid;
			else
				l=mid+1;
		//	cout<<r<<" "<<qzh[r]<<endl;
		//	cout<<qzh[r]-qzh[mid-1]+m<<endl;
		}
	//	cout<<i<<" "<<l<<endl;
		ans=max(ans,i-l+1);
	}
	cout<<ans;
	return 0;
}