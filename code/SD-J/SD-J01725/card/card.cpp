#include<bits/stdc++.h>
using namespace std;
//queue<int> a;
const int N=5e5+10;
int q[N],sum[N];
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>q[i];
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			sum[q[j]]++;
		}
	}
	for(int i=1;i<=m;i++)cout<<sum[i]<<" ";
	return 0;
}
