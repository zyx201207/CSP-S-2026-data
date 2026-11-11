#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define N 500010
#define _for(i,u,v) for(int i=(u);i<=(v);i++)
#define for_(i,u,v) for(int i=(u);i>=(v);i--)
ll a[N],b[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	int n,ans=1; ll m;
	cin>>n>>m;
	_for(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	_for(i,1,n) b[i]=a[i]+b[i-1];
	int sum=1;
	_for(i,1,n){
		if(a[i]*i-b[i]<=m){ ans=i; continue; }
		int l=sum,r=i; sum=i;
		while(l<r){
			int mid=(l+r)>>1;
			if(a[i]*(i-mid+1)-(b[i]-b[mid-1])<=m) r=mid,sum=mid;
			else l=mid+1;
		} ans=max(ans,i-sum+1);
	} cout<<ans<<"\n";
}

