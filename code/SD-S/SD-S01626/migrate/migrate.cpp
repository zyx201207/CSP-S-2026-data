#include <bits/stdc++.h>
#define prs " \n"
#define uinf 0x3f3f3f3f
#define i64 long long
#define u64 unsigned long long
using namespace std;
const int N=2e6+10;
vector<bitset<N>> e;
int T,c;
void s0lve()
{
	//vector<bitset<N>> e;
	int n,d;
	cin>>n>>d;
	vector<int> a(n+1,0),pth;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			for(int l=i;l<=j;l++)
			{
				
			}
		}
	}
}
int main()
{
	cin.tie(0)->sync_with_stdio(0);
//	freopen("migrate.in","r",stdin);
//	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--) s0lve();
	return 0;
}

