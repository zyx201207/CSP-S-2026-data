#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m;
int a[500005];
int s[500005];
int answer=0;
int two(int rr,int shu)
{
	int l=1,r=rr;
	int ans;
	while(l<=r){
		int mid=(l+r)/2;
		if(shu*(rr-mid+1)-(s[rr]-s[mid-1])<=m){
			ans=mid;r=mid-1;
		}
		else l=mid+1;
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int ll=two(i,a[i]);
		answer=max(answer,i-ll+1);
	}
	cout<<answer<<'\n';
	return 0;
 } 
