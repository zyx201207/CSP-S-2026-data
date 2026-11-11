#include<bits/stdc++.h>
using namespace std;
long long x[200010],sum,ans,n,l,r;
char a[200010];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>n;
	for(long long i=1;i<=n;i++)
		cin>>x[i]>>a[i];
	l=1,r=n;
	while(l<r){
		if(x[l]<x[r])
			ans+=x[l]*(a[l]!=a[r]),x[r]-=x[l],l++;
		else if(x[l]>x[r])
			ans+=x[r]*(a[l]!=a[r]),x[l]-=x[r],r--;
		else
			ans+=x[l]*(a[l]!=a[r]),l++,r--;
	}
	cout<<ans;
	return 0;
}