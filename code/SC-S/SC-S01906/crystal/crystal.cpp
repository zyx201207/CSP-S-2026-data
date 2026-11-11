#include<bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	scanf("%d%lld",&n,&m);
	vector<ll>a(n);
	for(int i=0;i<n;i++){
		scanf("%lld",&a[i]);
	}
	sort(a.begin(),a.end());
	vector<ll>s(n+1,0);
	for(int i=0;i<n;i++){
		s[i+1]=s[i]+a[i];
	}
	int l=0,ans=0;
	for(int r=0;r<n;r++){
		while(a[r]*(r-l+1ll)-(s[r+1]-s[l])>m){
			l++;
		}
		ans=max(ans,r-l+1);
	}
	printf("%d",ans);
	return 0;
} 