#include<bits/stdc++.h>
using namespace std;
int n,ans=0;
long long m,a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	int i=n,j=n;
	long long cst=0;
	while(1){
		while(cst+a[i]-a[j]<=m&&j>0){
			cst+=a[i]-a[j];
			j--;
		}
		ans=max(ans,i-j);
		if(j==0)break;
		i--;
		cst-=(i-j)*(a[i+1]-a[i]);
	}
	cout<<ans;
	return 0;
}
