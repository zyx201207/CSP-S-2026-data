#include<bits/stdc++.h>
using namespace std;

typedef long long ll;
const int N=5e5+10;
ll a[N];
int n;
ll m;
ll sum;
int ans;
int main()
{
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+1+n);
	int j=0;
	for(int i=1;i<=n;i++)
	{
		while(j<=n)
		{
			j++;
			if(sum+abs((a[j]-a[j-1])*(j-i))<=m)
			{
//				cout<<(j-i)<<" ";
			sum+=(a[j]-a[j-1])*(j-i);
//			cout<<i<<" "<<j<<" "<<sum<<" "<<(a[j]-a[j-1])*(j-i)<<"\n";
			}else break;
			
		}
		j--;
		sum-=a[j]-a[i];
//		cout<<i<<" "<<j<<" "<<sum<<"\n";
		ans=max(ans,j-i+1);
	} 
	cout<<ans;
	return 0;
}

