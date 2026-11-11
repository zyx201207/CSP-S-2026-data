#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=5e5+5;
int n,m,a[N],ma=-1e18,mi=1e18,ans,pos; 
int work(int x){
	int sum=0,y=0,b=m;
	int l=1,r=n,pos=0;
	while(l<r){
		int mid=(l+r)/2;
		if(a[mid]==x)l=mid+1;
		else if(a[mid]<x)l=mid+1;
		else r=mid;
	}
	for(int i=l;i>=1;i--){
		if(x-a[i]>=0){
			b-=x-a[i];
			if(b>=0)y++;
		}
	}
	ans=max(ans,y);
	if(b>=0){
		return 1;
	}
	else{
		return 0;
	}
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	pos=m;
	for(int i=1;i<=n;i++)cin>>a[i],mi=min(mi,a[i]),ma=max(ma,a[i]);
	sort(a+1,a+n+1);
	int l=mi,r=ma;
	for(int i=mi;i<=ma;i++)work(i);
	cout<<ans;
	return 0;
} 
