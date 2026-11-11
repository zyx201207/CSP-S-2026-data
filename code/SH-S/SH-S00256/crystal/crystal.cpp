#include <bits/stdc++.h>
using namespace std;
long long n,m,a[500010],s[500010];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;++i){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];		
	}
	int maxn=0;
	for(int i=1;i<=n;++i){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)/2,len=i-mid+1;
			if(a[i]*len-s[i]+a[mid-1]<=m){
				maxn=max(maxn,len);
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
	}
	cout<<maxn;
	return 0;
} 
