#include<bits/stdc++.h>
#define ll long long
using namespace std;

const int N=5e5+5;
int n,m,a[N];

int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);

	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==1)
	{
		cout<<n<<"\n";
		return 0;
	}
	else if(m==2)
	{
		int b[3],c[3];
		for(int i=n;i>=1;i--)
		{
			if(b[a[i]]) b[3-a[i]]=0;
			else b[a[i]]=1;
			c[1]+=b[1];
			c[2]+=b[2];
		}
		cout<<c[1]<<" "<<c[2]<<"\n";
	}
	else if(n<=5000)
	{
		map<int,int> mp;
		set<int> st;
		deque<int> q;
		for(int i=1;i<=n;i++)
		{
			st.clear();
			for(int j=i;j<=n;j++)
			{
				if(st.find(a[j])!=st.end())
				{
					while(!q.empty()&&q.back()!=a[j])
					{
						st.erase(q.back());
						q.pop_back();
					}
					/*q.push_back(a[j]);
					st.insert(a[j]);*/
				}
				else
				{
					st.insert(a[j]);
					q.push_back(a[j]);
				}
			}
			while(!q.empty())
			{
				mp[q.front()]++;
				//cout<<q.front()<<" ";
				q.pop_front();
			}
			//cout<<"\n";
		}
		for(int i=1;i<m;i++) cout<<mp[i]<<" ";
		cout<<mp[m]<<"\n";
	}
	else
	{
		for(int i=1;i<n;i++) cout<<i<<" ";
		cout<<n<<"\n";
	}
	return 0;
}
/*
zheng fan ze nan si hu xing bu tong ?
*/
