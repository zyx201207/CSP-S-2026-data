#include<bits/stdc++.h>
#define ll long long
#define i128 __int128
using namespace std;
const int N=5e5+145;
const int M=3e5+145;
int a[N],cnt[M];
bool cant[M],ins[M];
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n,m; cin>>n>>m;
	for (int i=1;i<=n;i++){
		cin>>a[i];
	}
	for (int t=1;t<=n;t++){
		memset(cant,0,sizeof(cant));
		memset(ins,0,sizeof(ins));
		stack<int> stk;
		for (int i=t;i<=n;i++){
			if (cant[a[i]]) continue;
			if (ins[a[i]]){
				while (!stk.empty()&&stk.top()!=a[i]){
					int u=stk.top();
					cant[u]=1;
					stk.pop();
					ins[u]=0;
				}
				continue;
			} else {
				stk.push(a[i]);
				ins[a[i]]=1;
			}
		}
		while (!stk.empty()){
			int u=stk.top();
			cnt[u]++;
			stk.pop();
		}
		cout<<"----";
		for (int k=1;k<=m;k++) cout<<cnt[k]<<" ";
		cout<<"\n";
	}
	for (int i=1;i<=m;i++) cout<<cnt[i]<<" ";
	return 0;
}

