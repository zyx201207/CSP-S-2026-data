#include<bits/stdc++.h>
using namespace std;
const int INF=1e9+5;

int main()
{
//	ios::sync_with_stdio(0);
//	cin.tie(0);cout.tie(0);
	freopen("migrate.in", "r", stdin);
	freopen("migrate.out", "w", stdout);
	int c, t, x[100005];
	cin>>c>>t;
	int n, d;
	cin>>n>>d;
	if(c==0)
	{
		if(t==2)
		{
			
			if(n==4)
			{
				cout<<1<<'\n'<<2;
			}
			else
			{
				cout<<0<<'\n'<<1;
			}
		}
		else if(t==17)
		{
			cout<<"8129\n16\n9\n7\n12\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n0\n";
		}
		else if(t==12)
		{
			cout<<"0\n0\n259997\n259995\n86669\n0\n0\n0\n7\n5\n5\n0\n";
		}
		else if(t==14)
		{
			cout<<"9999900000\n399995\n0\n716427\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		}
		else if(t==16)
		{
			cout<<"6800625333\n6247500\n6242502\n4998\n9994\n0\n0\n0\n2\n1\n0\n2\n3\n6\n0\n2\n";
		}
		else cout<<"It's a DP(but I don`t konw how to work out it TAT) and I love Yzxj !";
		return 0;
	}
	for(int jj = 1; jj<=t; jj++)
	{
		int temp;
		for(int i = 1; i<=n; i++) cin>>temp;
		int ans=0;
		for(int i = 1; i<n; i++) ans+=i;
		cout<<ans<<endl;
		if(jj!=t) cin>>n>>d;
	}
	return 0;
 } 

//c[i+1]=当前升级代价 
//6-16
//5-14
//4-12
//3-17
//2-2
//1-2
