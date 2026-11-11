#include<bits/stdc++.h>
using namespace std;
#define int long long
int n,k,ans,l,r;
char c;
string kl1,kl2,jj;
vector<int>s;
signed main()
{
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>k>>c;
		for(int j=1;j<=k;j++)
			kl1+=c,kl2=c+kl2;
	}
	for(int i=0;i<kl1.size()/2;i++)
		if(kl1[i]!=kl2[i])
		  ans++;
	cout<<ans;
	return 0;
}