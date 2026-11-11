#include<bits/stdc++.h>
using namespace std;
long long a[500005],n,m,s=0,k=0;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
	s+=a[i];
	if(s+m>=i*a[i]){
	k++;
	}else{
	break;}}
	cout<<k;
}
