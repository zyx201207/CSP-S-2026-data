#include<bits/stdc++.h>
using namespace std;
#define LL long long
const int N=5e5+10;
LL n,m,a[N],s[N],ans=INT_MIN;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	LL r=1;
	int t=0;
	for(LL i=1;i<=n;i++){
		t=0;
		while(t<=m&&r<=n){
			t=a[r]*(r-i+1)-(s[r]-s[i-1]);
			if(t<=m){
				r++;
			}
		}
		r--;
		ans=max(r-i+1,ans);
		// cout<<"\n";
	}
	cout<<ans;
	return 0;
}