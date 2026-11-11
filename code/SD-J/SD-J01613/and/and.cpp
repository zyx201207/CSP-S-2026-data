#include<bits/stdc++.h>
using namespace std;
long long n,m,js[200005],sum,maxx;
bool b[200005];
string s[200005];
int main() 
{
	ios::sync_with_stdio(false);cin.tie(0),cout.tie(0);
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout); 
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		s[i]+=' ';
		for(long long j=1;x;j++,maxx=max(maxx,j))
		{
			char c=x%2+'0';
			s[i]+=c;
			js[j]+=x%2;
			x/=2;
		}
	}
//	for(int i=1;i<=n;i++)cout<<s[i]<<' ';
	for(int i=maxx;i>=1;i--)
		if(js[i]>=m)
		{
			sum+=pow(2,(i-1));
			for(int j=1;j<=n;j++)
				if(b[j]==0)
					if(s[j][i]=='0'||s[j].size()<=i)
					{
						b[j]=1;
						for(int k=1;k<=s[j].size();k++)js[k]-=(s[j][k]=='1');
					}
		}
	cout<<sum;
	return 0;
}

