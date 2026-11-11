#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll a[500005],sum[300005];
bool vis[300005]={0};
stack<ll> st;
int main()
{
	std::ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n,m;
	cin>>n>>m;
	for(ll i=1;i<=n;i++)
		cin>>a[i];
//	cout<<1<<"\n";
	for(ll i=1;i<=n;i++)
	{
//		cout<<i<<"\n";
		memset(vis,0,sizeof(vis));
		for(ll j=i;j<=n;j++)
		{
//			cout<<j<<"\n";
			if(!vis[a[j]]){
				vis[a[j]]=1;
				st.push(a[j]);
//				cout<<"add:"<<i<<"->"<<j<<"\n";
			}else{
//				cout<<"detel:"<<i<<"->"<<j<<"\n";
				while(!st.empty()&&st.top()!=a[j])
				{
					vis[st.top()]=0;
					st.pop();
				}
			}
		}
		while(!st.empty()){
			sum[st.top()]++;
//			cout<<st.top()<<" ";
			st.pop();
		}
//		cout<<"\n";
	}
	for(ll i=1;i<=m;i++)
		cout<<sum[i]<<" ";
	return 0;
}

