#include<iostream>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;
vector<int> v[2000005];
int main()
{
	//system("fc /w hub.out hub.out");
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	for(int j=1;j<=t;j++)
	{
		int n,k;
		long long d;
		cin>>n>>k;
		for(int i=1;i<=n-1;i++)
		{
			int x,y;
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		cout<<n<<"\n";
	}
	return 0;	
}
