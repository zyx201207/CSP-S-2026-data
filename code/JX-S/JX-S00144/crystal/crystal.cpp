#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,ans,m;
long long a[N];
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		int sum=0,l=m;
		for(int j=i;j>=1;j--){
			if(l>=a[i]-a[j]){sum++;l=l-a[i]+a[j];}
		}
		if(sum>ans)ans=sum;
	}
	cout<<ans;
	return 0;
}
