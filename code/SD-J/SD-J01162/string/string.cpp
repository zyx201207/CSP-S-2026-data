#include<bits/stdc++.h>
using namespace std;
int n,a[200001],l,r;
long long ans;
char c[200001];
int main(){
	freopen("string.in","r",stdin),freopen("string.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n,l=1,r=n;
	for(int i=1;i<=n;i++)cin>>a[i]>>c[i];
	while(l<r){
		if(a[l]<a[r])ans+=(c[r]!=c[l])*a[l],a[r]-=a[l],a[l]=0,l++;
		else if(a[l]==a[r])ans+=(c[r]!=c[l])*a[l],a[l]=0,a[r]=0,l++,r--;
		else if(a[l]>a[r])ans+=(c[r]!=c[l])*a[r],a[l]-=a[r],a[r]=0,r--;
	}
	cout<<ans;
	return 0;
}
