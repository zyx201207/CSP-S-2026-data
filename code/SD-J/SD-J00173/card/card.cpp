#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,m,a[500005],ans[300005],ff[300005];
stack<int> p;
void f(int l){
	memset(ff,0,sizeof(ff));
	for(int i=l;i<=n;i++){
		if(!ff[a[i]]){
			ff[a[i]]=1;
			p.push(a[i]);
			continue;
		}
		while(!p.empty() && p.top()!=a[i])ff[p.top()]=0,p.pop();
	}
	while(!p.empty()){
		ans[p.top()]++;
		p.pop();
	}
}
signed main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)f(i);
	for(int i=1;i<=m;i++){
		cout<<ans[i];
		if(i!=m)cout<<' ';
	}
	return 0;
}

