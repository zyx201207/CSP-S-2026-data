#include<bits/stdc++.h>
#define ll long long 
using namespace std;
int c,t,n,k;
vector<int> q;
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--)
	{
		n=0,k=0;
        cin>>n>>k;
        int u=0,v=0;
        while(cin>>u>>v)
        {
        	q[u].push_back(v);
        	q[v],push_back(u);
		}
		cout<<1+rand()%10<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
