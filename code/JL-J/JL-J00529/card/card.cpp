/*
 ww
 tt
 ff
 why T4 damoni?
 I do not have time!!!!
 luogu 1842302
*/
#include<bits/stdc++.h>
using namespace std;
int a[200001];
int ans[200001][2];
int main()//1138
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	if(m==2)
	{
		int q=0,w=0;
		for(int i=1;i<=n;i++)
		{
			if(a[i]==1) q++;
			else w++;
		}
		int dif=abs(q-w);
		if(q>w) cout<<n-dif<<' '<<dif<<endl;
		else cout<<dif<<' '<<n-dif<<endl;//what is this? I do not know
	}
	for(int i=0;i<n;i++) cout<<0<<' ';
	return 0;
}
/*
	total: 100+[16,20]+[50,65]+0=[166,185]
	only 2=
	the diffculty:
	mid/up red
	up yellow / under green
	mid/up yellow
	???(maybe queue/set) but there is no time
		emm up green/under qing

	bye bye OI
	wait for S.....
					-----luogu 1842302 && _2025WANG72
*/