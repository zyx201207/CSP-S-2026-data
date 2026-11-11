#include<bits/stdc++.h> 
#define int long long
#define endl "\n"
using namespace std;
int n,m;
const int MAXN=2e5+500;
int a[MAXN],t[MAXN],t2[MAXN]; 
stack<int>st;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i;j<=n;j++)
		{
			st.push(a[j]);
			if(!st.empty()&&t[a[j]])
			{
				st.pop();
				while(!st.empty()&&st.top()!=a[j])
				{
					t[st.top()]=0;
					st.pop();
					if(st.top()==a[j])break;
				}
			}
			t[a[j]]=1;
		}
		while(!st.empty())
		{
			t2[st.top()]++;
			st.pop();
		}
		for(int i=1;i<=m;i++)
		{
			t[i]=0;
		}
	}
	for(int i=1;i<=m;i++)
	{
		cout<<t2[i]<<" ";
	} 
	return 0;
}
