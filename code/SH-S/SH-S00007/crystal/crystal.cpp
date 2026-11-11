#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],s[500005],ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){cin>>a[i];}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		long long l=0,r=i,mid;
		while(l!=r){
			mid=(l+r)>>1;
			if(a[i]*(i-mid)-s[i]+s[mid]<=m)r=mid;
			else l=mid+1;
		}
		ans=max(i-l,ans);
	}
	cout<<ans;
	return 0;
}
