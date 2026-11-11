#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[5000005],s[5000005];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	for(int len=1;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=len+l-1;
			if(a[r]*len-(s[r]-s[l-1])<=m)ans=max(ans,len);
			else continue;
			}
		}
	cout<<ans;
	return 0;
}
