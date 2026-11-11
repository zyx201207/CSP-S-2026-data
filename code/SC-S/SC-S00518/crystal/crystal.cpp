#include<bits/stdc++.h>
#define int long long
using namespace std;
long long a[500005],s[500005];
long long n,m;
bool check(int mid){
	long long tf=a[mid]*mid-s[mid];
//	cout<<s[mid]-s[0]<<' ';
	return tf<=m;
}
signed main(){
	ios_base :: sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	s[0]=0;
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
//		cout<<s[i]<<" ";
	}
	long long l=1,r=n,ans=0;
	while(l<=r){
		int mid=(l+r)/2;
		if(check(mid)){
			l=mid+1;
			ans=mid;
		}else{
			r=mid-1;
		}
	}
	cout<<ans;
	return 0;
}