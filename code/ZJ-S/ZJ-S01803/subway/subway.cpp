#include<bits/stdc++.h>
using namespace std;
int main()
{
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	long long c,n,m,d,q;
	cin>>c>>n>>m>>d>>q;
	for(long long i=1;i<=q;i++)
	{
		srand(time(0));
		cout<<rand()<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
