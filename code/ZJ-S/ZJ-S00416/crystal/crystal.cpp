#include<bits/stdc++.h>
#define ll long long
using namespace std;
#define N 500009
ll n,m;
ll a[N],s[N];
ll sum(int l,int r){
	return s[r]-s[l-1];
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	s[0]=0;
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,res=i;
		while(l<=r){
			int mi=(l+r)/2;
			if(a[i]*(i-mi+1)-sum(mi,i)<=m)res=mi,r=mi-1;
			else l=mi+1;
		}
		ans=max(ans,i-res+1);
	}
	cout<<ans;
	return 0;
}
