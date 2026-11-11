#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
long long n,m,a[N],dp;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	sort(a+1,a+n+1);
	long long sum=0;
	for(int i=1;i<=n;i++){
		sum=0;
		for(int k=1;k<=i;k++)
			sum+=a[i]-a[k];
		if(sum>m)
			continue;
		else
			dp++;
	}
	cout<<dp++;
	return 0;
}