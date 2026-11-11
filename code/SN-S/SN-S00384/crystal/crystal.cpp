#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[500010],qjh[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		qjh[i]=qjh[i-1]+a[i];
	}
	int ans=-1;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1,mid;
		while(l<=r){
			mid=(l+r)/2;
			if(a[i]*(i-mid)-(qjh[i-1]-qjh[mid-1])<=m){
				r=mid-1;
				ans=max(ans,i-mid+1);
			}
			else{
				l=mid+1;
			}
		}
	}
	cout<<ans;
	return 0;
}
