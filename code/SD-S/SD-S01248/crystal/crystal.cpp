#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[510000],qzh[510000];
int n,m;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	qzh[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		qzh[i]=qzh[i-1]+a[i];
	}
	int ans=-1;
	for(int i=1;i<=n;i++){
		int l=1,r=i-1;
		while(l<=r){
			int mid=(l+r)/2;
			if((i-mid)*a[i]-(qzh[i-1]-qzh[mid-1])<=m){
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-l+1);
	} 
	cout<<ans<<endl;
	return 0;
}
