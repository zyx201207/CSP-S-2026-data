#include<bits/stdc++.h>
using namespace std;
int n;
long long m,a[500005],d[500005],p[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=2;i<=n;i++){
		d[i-1]=a[i]-a[i-1];
	}
	for(int i=n;i>=1;i--){
		d[i]=d[i+1]+d[i];
	}
	for(int i=1;i<=n;i++){
		p[i]=p[i-1]+d[i];
	}
	int cnt=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,ans=0;
		while(l<=r){
			int mid=(l+r)/2;
			if(p[i]-p[mid-1]-d[i]*(i-mid+1)>m){
				l=mid+1;
			}
			else{
				r=mid-1;
				ans=mid;
			}
		}
		cnt=max(cnt,i-ans+1);
	}
	cout<<cnt;
	return 0;
}