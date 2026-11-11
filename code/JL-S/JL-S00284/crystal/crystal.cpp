#include<bits/stdc++.h>
using namespace std;
const int N=500005;
long long n,m;
long long a[N],s[N];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio();
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int ans=0;
	for(int i=1;i<=n;i++){
		int l=1,r=i,t=0;
		while(l<=r){
			long long mid=l+r>>1;
			long long num=i-mid+1;
			long long v=a[i]*num-(s[i]-s[mid-1]);
			if(v<=m){
				r=mid-1;
				t=num;
			}else{
				l=mid+1;
			}
		}
		ans=max(ans,t);
	}
	cout<<ans;
	return 0;
}