#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int n,maxn;
long long m,a[N],s[N];
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	for(int i=1;i<=n;i++){
		int l=0,r=i,best=i;
		while(l<=r){
			int mid=(l+r>>1);
			if(a[i]*(i-mid)-s[i]+s[mid]<=m)best=mid,r=mid-1;
			else l=mid+1;
		}
		maxn=max(maxn,i-best);
	}
	cout<<maxn;
	return 0;
}

