//西安含光中学 吕家名 SN-S00506 
#include<bits/stdc++.h>
using namespace std;
long long x[2000010];
void solvea()
{
	int n,d;
	cin>>n>>d;
	cout<<n<<" "<<d<<"\n";
	if(n<=1)
	{
		cout<<"0\n";
		return;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>x[i];
	}
	int u=x[2]-x[1];
	if(d<u)
	{
		cout<<"0\n";
		return;
	}
}
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int c,t;
	cin>>c>>t;
	if(11<=c&&c<=12)
	{
		while(t--)
		{
			solvea();
		}
	}
}
