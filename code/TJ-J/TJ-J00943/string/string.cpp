#include<bits/stdc++.h>
using namespace std;
long long n,a[200010];
char c[200010];
long long ans;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i]>>c[i];
	}
	long long l=1,r=n;
	while(l<=r){
		long long t=min(a[l],a[r]);
		if(c[l]!=c[r])ans+=t;
		a[l]-=t;
		if(a[l]==0)++l;
		a[r]-=t;
		if(a[r]==0)--r;
	}
	cout<<ans;
	return 0;
}
