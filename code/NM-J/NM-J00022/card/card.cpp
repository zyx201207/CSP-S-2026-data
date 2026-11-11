#include<bits/stdc++.h>
using namespace std;
int n,m,a[500005],k[300005],t[300005],nxt[300005];
stack<int>s;
bitset<500005>b;
int main(){
	int i,j;
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(i=1;i<=n;i++)cin>>a[i];
	for(i=n;i>=1;i--){
		if(!k[a[i]])nxt[i]=i,k[a[i]]=i;
		else nxt[i]=k[a[i]];
	}
	for(i=n;i>=1;i--){
		while(!s.empty())s.pop();
		b.reset();
		for(j=i;j<=n;j++){
			j=nxt[j];
			if(b[a[j]]){
				int x=s.top();
				while(s.size()>1&&x!=a[j]){
					s.pop();
					b[x]=0;
					x=s.top();
				}
			}else s.push(a[j]),b[a[j]]=1;
		}
		for(j=1;j<=m;j++)if(b[j])t[j]++;
	}
	for(j=1;j<=m;j++)cout<<t[j]<<' ';
	return 0;
}
