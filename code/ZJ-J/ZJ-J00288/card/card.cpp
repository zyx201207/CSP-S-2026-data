#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],b[300005],c[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.in","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		memset(b,0,sizeof(b));
		stack<ll> s;
		for(int j=i;j<=n;j++)
		{
			if(b[a[j]]==0)
			{
				s.push(a[j]);
				b[a[j]]++;
			}
			else{
				while(b[a[j]]){
					b[s.top()]--;
					s.pop();
				}
				s.push(a[j]);
				b[a[j]]++;
			}
		}
		while(s.size()){
			c[s.top()]++;
			s.pop();
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<c[i]<<" ";
	}
}
