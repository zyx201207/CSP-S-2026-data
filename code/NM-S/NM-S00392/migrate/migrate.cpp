#include<bits/stdc++.h>
using namespace std;
int n,t1,c;
long long d;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t1;
	for(int z=1;z<=t1;z++)
	{
		int h=1,t=1;
		deque <long long> q;
		deque <long long> q2;
		cin>>n>>d;
		vector <long long> a(1010);
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		q.push_back(1);
		q2.push_back(0);
		
		while(h<=t)
		{
			int cnt=q[h]+1;
			while(a[q[h]]+d>=a[cnt]&&cnt<=n)
			{
				q.push_back(cnt);
				q2.push_back(h);
				cnt++;
				t++;
			}
			h++;
		}
		for(int i=0;i<=h;i++)
		{
			cout<<q[i]<<' ';
		}
	}	
}
