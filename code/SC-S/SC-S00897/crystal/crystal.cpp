#include<bits/stdc++.h>
using namespace std;
#define fo(i,begin,end) for(int i=begin;i<=end;++i)
#define ll long long
const int N=5e5+5;
int n,m,ans;
ll a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	fo(i,1,n) cin>>a[i];
	sort(a+1,a+n+1);
	fo(i,1,n) s[i]=s[i-1]+a[i];
	fo(i,1,n){
		int l=1,r=i-1;
		while(l<r){
			int mid=(l+r)>>1;
			if((i-mid)*a[i]-s[i-1]+s[mid-1]<=m) r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-r+1);
	}
	cout<<ans;
	return 0;
}
