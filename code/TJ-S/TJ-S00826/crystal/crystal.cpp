#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500005],cnt,i,minn=2000000000,t;
int main(){
	freopen("crystal.in","r",stdin),freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=1;i<=n;i++)for(int j=1;j<=n;j++)if(a[j]>a[j+1])t=a[j],a[j]=a[j+1],a[j+1]=t;
	int k=a[2]-a[1];
	for(i=1;i<=n;i++)a[i]+=k;
	for(i=1;cnt<=m;i++)cnt+=i*k;
	cout<<min(i-1,n);
	return 0;
}
