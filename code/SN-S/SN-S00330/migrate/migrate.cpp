//罗何烨 西安中学 SN-S00330 
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;
long long n,m,num,ans,k;
long long a[N],b[N];
int main()
{
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;++i)
	{
		cin>>k>>num;
		for(int j=1;j<=k;++j)
		{
			cin>>a[j];
		}
		cout<<a[n]/2%2<<'\n';
	}
	return 0;
	
}
