#include<bits/stdc++.h>
using namespace std;
int C,T;
int n,k;
vector<int>v[500005];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--)
	{
		cin>>n>>k;
		for(int i=1;i<n;i++)
		{
			int t1,t2;
			cin>>t1>>t2;
			v[t1].push_back(t2);
		}
		
	}
	return 0;
}
