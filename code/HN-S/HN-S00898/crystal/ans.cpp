#include <bits/stdc++.h>

namespace solve
{
	void main()
	{
		int a,b;
		std::cin>>a>>b;
		std::cout<<a+b<<'\n';
	}
}

int main()
{
using namespace std;
#define PROBLEM ""
#if 1
	freopen(PROBLEM".in","r",stdin);
	freopen(PROBLEM".ans","w",stdout);
#endif
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	int T;std::cin>>T;
	while(T--) solve::main();
	return 0;
}