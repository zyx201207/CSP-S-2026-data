#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005];
int nxt[500005][35],same[i],maxl;
vector <int>
bool f[30005]
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>a[i];
		same[a[i]].push_back(i);
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=0;j+1<same[i].size();j++)
		{
			nxt[same[i][j]] = same[i][j+1];
		}
		nxt[same[i][int(same[i].size()-1)]]
	}
	for(int i=1;i<=n;i++)cout<<nxt[i]<<' ';
	{
		for(int j=i;j<=n;j++)
		{
			cout<<j<<' ';
			ans[a[j]]++;
			cout<<ans[a[j]]<<endl;
			if(nxt[j] != 1e9)j=nxt[j];
		}
		cout << endl;
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
