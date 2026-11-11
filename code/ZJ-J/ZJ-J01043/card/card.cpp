#include<bits/stdc++.h>
using namespace std;
int n,m,a[500010],ls[300010],ans[300010],d[500010];
int chu[500010],in[500010];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=n;i>=1;i--){
		if(!ls[a[i]])ls[a[i]]=i,chu[i]=i+1,in[i+1]++;
		else{
			chu[i]=chu[ls[a[i]]];
			in[chu[i]]++;
		}
	}
	queue<int>q;
	for(int i=1;i<=n;i++)if(!in[i])q.push(i);
	for(int i=1;i<=n;i++)d[i]=1;
	while(q.size()){
		int x=q.front();q.pop();
		ans[a[x]]+=d[x];
		d[chu[x]]+=d[x];
		if(!--in[chu[x]])q.push(chu[x]);
	}
	for(int i=1;i<=m;i++)cout<<ans[i]<<' ';
	return 0;
}
