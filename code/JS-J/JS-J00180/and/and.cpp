#include <iostream>
#include <cmath>
using namespace std;
int m,n,n2;
bool a[200005][35];
int b[35],ans;
bool q[200005];
void f(int id,int s)
{
	int i=1;
	while(s)
	{
		a[id][i]=s%2;
		b[i]+=s%2;
		s/=2;
		i++;
	}
	return;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	n2=n;
	for(int i=0;i<n;i++)
	{
		int s;
		cin>>s;
		f(i,s);
	}
	int now=30;
	while (now>=0)
	{
		if(b[now]<m)
		{
			now--;
			continue;
		}
		ans+=pow(2,now)/2;
		for(int i=0;i<n;i++)
		{
			if(a[i][now]==0 && q[i]==0)
			{
				q[i]=1;
				for(int j=1;j<30;j++)
				{
					b[j]-=a[i][j];
				}
			}
		}
		now--;
	}
	cout<<ans;
	return 0;
}

