#include<bits/stdc++.h>
using namespace std;
const int N=500010;
long long n,m,a[N],ans=1,sum;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	//cout<<n<<endl;
	sort(a+1,a+1+n);
	sum=0;
	for(long long l=1,r=2;r<=n;r++)
	{
		//cout<<"qzq"<<endl;
		sum+=(r-l)*(a[r]-a[r-1]);
		while(sum>m)
		{
			sum-=a[r]-a[l];
			l++;
		}
		ans=max(ans,r-l+1ll);
	}
	cout<<ans;
	return 0;
}
