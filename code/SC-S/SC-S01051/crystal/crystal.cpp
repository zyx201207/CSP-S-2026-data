#include<iostream>
#include<algorithm>
using namespace std;
using int64=long long;
#define N 500001
int n,i,l,r,mid,ans=0;int64 m,a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;++i)cin>>a[i];
	stable_sort(a+1,a+1+n);
	for(i=1;i<=n;++i){
		s[i]=s[i-1]+a[i];
		l=0;r=i;
		while(l<r){
			mid=l+r>>1;
			if(a[i]*(i-mid)-s[i]+s[mid]>m)l=mid+1;
			else r=mid;
		}ans=max(ans,i-l);
	}cout<<ans;
	return 0;
}