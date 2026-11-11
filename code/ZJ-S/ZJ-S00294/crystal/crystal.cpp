//luogu _Sxi_ 
#include<bits/stdc++.h>
#define int long long
#define writen ios::sync_with_stdio(false);
#define by cin.tie(0);
#define Sxi cout.tie(0)
using namespace std;
const int N=1e6+10;
int n,m,t,k,a[N],b[N];
signed main()
{
	writen by Sxi;
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	sort(a+1,a+n+1);
	for(int i=1;i<n;i++)
	{
		b[i]=a[i+1]-a[i];
	}
	deque<int> q;
	int now=m,cc=0,mx=0,backi=1,fronti=-1;
	for(int i=1;i<=n;i++)
	{
		while(now-b[i-1]*cc<0&&q.size())
		{
			now+=a[fronti]-a[backi];
			backi++;
			cc--;
			//cout<<"+"<<a[fronti]-a[backi]<<"\n";
			q.pop_back();
			//cout<<"pop:"<<now<<"\n";
		}
		if(now-b[i-1]*cc>=0)
		{
			q.push_front(b[i]);
			fronti=i;
			now-=b[i-1]*cc;
			cc++;
			mx=max(mx,cc);
			//cout<<"push:"<<now<<"\n";
		}
	}
	cout<<mx;
	return (0^0);
}

