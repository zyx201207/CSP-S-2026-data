#include<bits/stdc++.h>
#define endl '\n'
#define N 500005
#define int long long
using namespace std;
int n,m,a[N],s[N],ans=1;
bool check(int l,int r){
	int sum=a[r]*(r-l);
	int v=sum-(s[r-1]-s[l-1]);
	return v<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	if(a[1]<0)
		for(int i=n;i>=1;i--)
			a[i]+=abs(a[1]);
	for(int i=1;i<=n;i++)
		s[i]=s[i-1]+a[i];
	for(int i=2;i<=n;i++){
		int l=1,r=i;
		while(l<r){
			int mid=(l+r>>1);
			if(check(mid,i)) r=mid,ans=max(ans,i-mid+1);
			else l=mid+1;
		}
	}
	cout<<ans;
}
/*
5 5
 1 2 4 8 9
*/