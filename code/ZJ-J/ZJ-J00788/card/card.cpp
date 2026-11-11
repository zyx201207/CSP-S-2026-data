#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans[500005];
bool ok[500005],flag=1;
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],flag&=(a[i]>=a[i-1]);
	if(m==1) return cout<<n,0;
	if(flag==1){
		for(int i=1;i<=n;i++){
			if(a[i]!=a[i+1]){
				cout<<i<<" ";
			}
		}
		return 0;
	}
	for(int i=1;i<=n;i++){
		stack<int> q;
		int cnt;
		memset(ok,false,sizeof(ok));
		for(int j=i;j<=n;j++){
			if(q.empty()) ok[a[j]]=1,q.push(a[j]);
			if(ok[a[j]]) while(!q.empty()&&q.top()!=a[j]) ok[q.top()]=0,q.pop();
			else ok[a[j]]=1,q.push(a[j]);
		}
		while(!q.empty()) ans[q.top()]++,q.pop();
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<" ";
}
/*
4 3
1 2 1 3

10 3
3 1 2 1 3 2 3 1 2 1
3:3
1:4
2:3
*/