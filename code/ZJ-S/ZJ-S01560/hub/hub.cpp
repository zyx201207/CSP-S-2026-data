#include<bits/stdc++.h>
using namespace std;
int c,t,n,k;
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(nullptr);cout.tie(nullptr);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	srand(time(0));
	while (t--)
	{
		cout<<rand()%100<<endl;
	}
	return 0;
}
