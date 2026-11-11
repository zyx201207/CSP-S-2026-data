/*
Can I do it?
I cannot.
I've tried my best.
RP++.
*/

#include<bits/stdc++.h>
using namespace std;

int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	srand(time(0));
	int c, t;
	cin>>c>>t;
	for(int i = 1; i <= t; i ++)
	{
		int n;
		cin>>n;
		cout<<rand() % n<<endl;
	}
	return 0;
}
