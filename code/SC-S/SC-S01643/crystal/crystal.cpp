#include<bits/stdc++.h>
using namespace std;
int n;
long long a[500005],b[500005]={0};
long long m;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=2;i<=n;i++)
		b[i]=(i-1)*(a[i]-a[i-1])+b[i-1];
	int ans=1;
	for(int i=2;i<=n;i++){
		if(b[i]<=m)
			ans=i;	
	}cout<<ans;
	return 0;
}