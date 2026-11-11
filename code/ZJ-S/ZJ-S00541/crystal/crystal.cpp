#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5,INF=1e12+1;
int n,m,a[N],s[N];
bool check(int d){
	int h=a[d]*d-s[d];
	return h<=m;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	s[0]=0;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		s[i]=s[i-1]+a[i];
	}sort(a+1,a+n+1);
	int l=1,r=n,mid,ans=0;
	while(l<=r){
		mid=l+(r-l)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}cout<<ans;
	return 0;
}
