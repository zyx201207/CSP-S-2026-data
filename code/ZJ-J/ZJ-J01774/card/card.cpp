#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500100],f[500100],b[500100];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(f,0,sizeof(f));
		stack<ll> q;
		for(int j=i;j<=n;j++){
			if(f[a[j]]){
				while(q.top()!=a[j]) f[q.top()]=0,q.pop();
				f[a[j]]=0;
				q.pop();
			}
			q.push(a[j]);
			f[a[j]]=1;
		}
		while(!q.empty()){
			b[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++){
		cout<<b[i]<<" ";
	}
	return 0;
}
/*
4 3
1 2 1 3
answer 3 1 4

10 3
3 1 2 1 3 2 3 1 2 1
answer 10 3 3





*/
