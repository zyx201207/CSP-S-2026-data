#include<bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
#define int long long 

inline int read()
{
	int x(0);
	char ch(getchar());
	while(!isdigit(ch))ch=getchar();
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x;
}

signed main()
{
	srand(time(0)^clock());
	while(true)
	{
		freopen("hub.in","w",stdout);
		cout<<"0 1\n";
		int n=8,k=rand()%(n-2)+2;
		cout<<n<<" "<<k<<"\n";
		for(int i=1;i<n;i++)
		{
			cout<<rand()%i+1<<" "<<i+1<<"\n";
		}
		cerr<<"???\n";
		system("./hub");
		system("./baoli");
		fclose(stdout);
		int a,b;
		freopen("hub.out","r",stdin);
		cin>>a;
		freopen("std.out","r",stdin);
		cin>>b;
		if(a!=b)
		{
			cerr<<"wa\n";
			return 0;
		}
		cerr<<"ok\n";
	}
}