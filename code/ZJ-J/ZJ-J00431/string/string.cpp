#include <bits/stdc++.h>
using namespace std;
long long a[200200];
char b[200200];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i]>>b[i];
	int l=1,r=n;
	long long ans=0;
	while(l<r){
		if(b[l]!=b[r])ans+=min(a[l],a[r]);
		long long h=a[l];
		a[l]-=a[r],a[r]-=h;
		if(a[l]<=0)l++;
		if(a[r]<=0)r--;
	}
	cout<<ans;
	return 0;
}


