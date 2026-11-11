//罗何烨 西安中学 SN-S00330 
#include<iostream>
#include<algorithm>
using namespace std;
const int N=1e5+5;
long long n,m,num,ans,k,d,q,x,y;
void dijkstar(int l);
long long a[N],b[N],c[N];
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>num>>n>>m>>d>>q;
	for(int i=1;i<=m;++i)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;++i)
	{
		cin>>k;
		for(int j=1;j<=k;++j)
		{
			cin>>c[j]>>c[j];
		}
	}
	for(int i=1;i<=q;++i)
	{
		cin>>x>>y;
	}
	for(int i=1;i<=n;++i)
	{
		ans+=a[i];
	}
	cout<<ans;
	return 0;
	
}
