#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
int t=1;
const int N=2e5+50;
int n,m,num; 
struct Trie_node{int son[2],cnt;};
struct Trie
{
	Trie_node a[32*N];int idx;
	int newnode()
	{
		idx++;
		a[idx].son[0]=0;a[idx].son[1]=0;a[idx].cnt=0;
		return idx;
	}
	void add(int x)
	{
		int nw=0,id;
		for(int i=(1<<29);i>0;i>>=1)
		{
			id=x>=i;if(id)x-=i;
			if(!a[nw].son[id])a[nw].son[id]=newnode();
			nw=a[nw].son[id];
			a[nw].cnt++;
		}
	}
	int find(int x)
	{
		queue<int>q;
		q.push(0);
		int len,cnt1,ans=0,nw;
		for(int r=(1<<29);r>0;r>>=1)
		{
			len=q.size();cnt1=0;
			for(int i=1;i<=len;i++)
			{
				nw=q.front();q.pop();q.push(nw);
				cnt1+=a[a[nw].son[1]].cnt;
			}
			if(cnt1>=x)
			{
				ans+=r;
				for(int i=1;i<=len;i++)
				{
					nw=q.front();q.pop();
					if(a[nw].son[1])q.push(a[nw].son[1]);
				}
			}
			else
			{
				for(int i=1;i<=len;i++)
				{
					nw=q.front();q.pop();
					if(a[nw].son[1])q.push(a[nw].son[1]);
					if(a[nw].son[0])q.push(a[nw].son[0]);
				}
			}
		}
		return ans;
	}
}T1;
void solve()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>num;
		T1.add(num);
	}
	cout<<T1.find(m)<<'\n';
	return ;
}
int main()
{
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);
//	cin>>t;
	while(t--)solve();
	return 0;
}

