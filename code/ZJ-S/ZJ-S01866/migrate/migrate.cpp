#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
queue<long long> q;
long long k,lk,c,T,n,d,a,ans;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>c>>T;
	while(T--)
	{
		k=0;
		lk=0;
		cin>>n>>d;
		for(int i=1;i<=n;++i)
		{
			cin>>a;
			q.push(a);
			while(!q.empty())
			{
				long long op=q.front();
				if(a-op>d)
				{
					q.pop();
					k--;
				}
				else break;
			}
			if(k==lk)
			{
				ans++;
			}
			k++;
			lk=k;
		}
		while(!q.empty())
		{
			q.pop();
		}
		cout<<0<<"\n";
	}
	return 0;
}
