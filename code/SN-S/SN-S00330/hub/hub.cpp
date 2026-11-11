//罗何烨 西安中学 SN-S00330 
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;
long long n,m,num,ans,k,c;
long long a[N],b[N];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>c>>n;
	for(int i=1;i<=n;++i)
	{
		cin>>k>>num;
		for(int j=1;j<=k;++j)
		{
			cin>>a[j]>>b[j];
		}
		cout<<a[n]/2%2<<'\n';
	}
	return 0;
	
}
