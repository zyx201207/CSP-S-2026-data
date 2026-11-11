#include<bits/stdc++.h>
using namespace std;
vector<int> v;
int main(){
	//freopen("migrate.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	int c,t;
	cin>>c>>t;
	while(t--)
	{
		int n,d;
		cin>>n>>d;
		for(int i=1;i<=n;i++)
		{
			int x;
			cin>>x;
			v.push_back(x);
		}
	}
	cout<<0<<endl<<0; 
	return 0;
}
