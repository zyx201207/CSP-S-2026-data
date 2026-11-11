#include<bits/stdc++.h>
using namespace std;
#define int long long
int used[300005],n,m;
int a[500005];
int cnt[300005];
int cx[300005];
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i],cx[a[i]]++;
	int xy=1;
	for(int i=1;i<n;i++)
		if(a[i+1]<a[i]){
			xy=0;
			break;
		}
	if(xy){
		for(int hmx=1;hmx<=m;hmx++)
			cout<<hmx+cx[a[hmx]]-1<<' ';
		return 0;
	}
	for(int i=1;i<=n;i++){
		memset(used,0,sizeof(used));
		stack<int> q;
		for(int j=i;j<=n;j++){
			if(!used[a[j]]) used[a[j]]=1,q.push(a[j]);
			else while(q.top()!=a[j]) used[q.top()]=0,q.pop();
		}
		while(!q.empty()) cnt[q.top()]++,q.pop();
	}
	for(int i=1;i<=m;i++) cout<<cnt[i]<<' ';
	return 0;
}
