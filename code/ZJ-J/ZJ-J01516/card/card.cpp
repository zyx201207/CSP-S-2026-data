#include<bits/stdc++.h>
using namespace std;
#define int long long
#define N 500010
int n,m,a[N],ans[N],t[N];
stack<int> q;
signed main(){
//	ios::sync_with_stdio(0);
//	cin.tie(NULL);
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(t,0,sizeof(t));
		for(int j=i;j<=n;j++){
			if(t[a[j]]==0){
				q.push(a[j]);
				t[a[j]]=1;
				continue;
			}
			while(q.top()!=a[j]){
				t[q.top()]=0;
				q.pop();
			}
			t[a[j]]=1;
		}
		while(q.size()){
			ans[q.top()]++;
			q.pop();
		}
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<" ";
}
