#include<bits/stdc++.h>
using namespace std;
int n,m;
vector<int> v;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		v.push_back(x);
	}
	sort(v.begin(),v.end());
	int ans=v[n-1];
	for(int i=2;i<=m;i++)
	{
		ans=ans&v[n-i];
	}
	cout<<ans; 
	return 0;
}
