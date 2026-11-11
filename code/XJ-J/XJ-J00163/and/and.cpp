#include<bits/stdc++.h>
#define ll long long
using namespace std;
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	vector<int> s;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		s.push_back(x);
	}
	
	sort(s.begin(),s.end(),greater<int>());
	int sum=s[0];
	
	for(int i=1;i<m;i++)
	{
		sum=(sum & s[i]);
	}
	cout<<sum;
	return 0;
}

