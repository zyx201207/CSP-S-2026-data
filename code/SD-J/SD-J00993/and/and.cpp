#include<iostream>
using namespace std;
int n,m;
long long a[200100];
int g[200100];
long long cnt=-1;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin >> n >> m;
	for(int i=1;i<=n;i++)
	{
		cin >> a[i];
		g[i]=1;
	}
	for(long long l=1<<30;l>0;l=l>>1)
	{
		int k=0;
		for(int i=1;i<=n;i++) if(g[i]&&(a[i]&l)) k++;
		if(k<m) continue;
		//cout << k << ')';
		for(int i=1;i<=n;i++) if(g[i])
		{
			if((a[i]&l)==0) g[i]=0;
		}
	}
	for(int i=1;i<=n;i++) if(g[i])
	{
		//cout << a[i] << ']';
		if(cnt==-1) cnt=a[i];
		else cnt=(cnt&a[i]);
	}
	cout << cnt;
	return 0;
}
