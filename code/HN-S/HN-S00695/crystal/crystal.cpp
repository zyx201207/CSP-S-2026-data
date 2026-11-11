#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
long long a[N],d[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n;
	long long m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		d[i]=d[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,mi=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(1ll*(i-mid+1)*a[i]-(d[i]-d[mid-1])<=m){
				mi=min(mi,mid);
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-mi+1);
	}
	cout<<ans<<endl;
	return 0;
}