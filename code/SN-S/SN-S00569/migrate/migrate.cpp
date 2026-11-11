#include<bits/stdc++.h>
#define ull unsigned long long
#define pii pair<int,int>
using namespace std;
const int n=2e6;
ull T,c,N,D;
ull A[n];
int main()
{
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>T;
	while(T--)
	{
		cin>>N>>D;
		for(int i=1;i<=N;i++)cin>>A[i];
		if(c==11||c==12)
		{
			ull dis=A[2]-A[1];
			if(D<dis*2||N<2*(D/dis))
			{
				cout<<"0\n";
				continue;
			}else cout<<N-2*(D/dis)+1<<"\n";
		}else cout<<"0\n";
	}
	return 0;
}

