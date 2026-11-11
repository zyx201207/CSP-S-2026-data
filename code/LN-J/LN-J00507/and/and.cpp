#include<bits/stdc++.h>
using namespace std;
#define gc getchar_unlocked
#define pc putchar_unlocked
int t[4000005][2],cnt=0,n,m;
int sz[4000005];
void read(int &x)
{
	x=0;
	char c=gc();
	bool flg=0;
	while(c<'0' || c>'9')
	{
		if(c=='-') flg=1;
		c=gc();
	}
	while(c>='0' && c<='9')
	{
		x=x*10+c-'0';
		c=gc();
	}
	if(flg) x=-x;
}
void write(int x)
{
	
	if(x<0) x=-x,pc('-');
	if(x>=10) write(x/10);
	pc(x%10+'0');
}
void insert(int x)
{
	int p=0;
	for(int i=20;i>=0;i--)
	{
		int c=(x>>i)&1;
		//cout<<c<<" ";
		if(!t[p][c]) t[p][c]=++cnt;
		sz[t[p][c]]++;p=t[p][c];
	}
	//cout<<"\n";
}
long long query()
{
	long long ans=0;
	vector<int> v;
	v.push_back(0);
	for(int i=20;i>=0;i--)
	{
		int total=0;
		for(int x:v)
		{
			total+=sz[t[x][1]];
			//if(sz[t[x][1]]) cout<<sz[t[x][1]]<<" ";
		}
		//cout<<"\n total "<<total<<"\n";
		if(total<m) 
		{
			int old=v.size();
			for(int j=0;j<old;j++)
			{
				if(t[v[j]][1]) v.push_back(t[v[j]][1]);
				v[j]=t[v[j]][0];
			}
		}
		else
		{
			for(int &x:v)
			{
				x=t[x][1];
			}
			ans+=(1ll<<i);
		}
		//cout<<"ans:"<<ans<<"\n";
	}	
	return ans;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	read(n);read(m);
	for(int i=1,x;i<=n;i++) 
	{
		
		read(x);
		insert(x);
	}
	write(query());
	return 0;
}
