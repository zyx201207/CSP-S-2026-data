#include<bits/stdc++.h> 
using namespace std;
int a[500005],b[500005];
long long n,m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	long long n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		int u;
		cin>>u;
		a[i]=u;
	}
	sort(a+1,a+n+1);
	int ans=-1;
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int mid=1;mid<=n;mid++){
		int l=1,r=mid,ans2=-1;
		while(l<=r){
			int mid2=(l+r)/2;
			if(a[mid]*(mid-mid2)-(b[mid-1]-b[mid2-1])<=m){
				ans2=max(ans2,mid-mid2+1);
				r=mid2-1;
			}
			else{
				l=mid2+1;
			}
		}
		ans=max(ans,ans2);
	}
	cout<<ans;
	return 0;
}
