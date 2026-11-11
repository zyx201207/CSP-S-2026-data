#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=5e5+5;
ll a[N],s[N];
int ans;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=i+1,r=n,an=0;
		while(l<=r){
			int mid=(l+r)>>1;
			int len=mid-i+1;
			if(a[mid]*len-(s[mid]-s[i-1])<=m){
				l=mid+1;
				an=len;
			}
			else{
				r=mid-1;
			}
		}
		ans=max(ans,an);
	}
	cout<<ans;
	return 0;
}
