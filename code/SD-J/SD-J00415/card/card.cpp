#include<bits/stdc++.h>
using namespace std;
using LL=long long;
using ull=unsigned long long;
using i128=__int128;
using Pii=pair<int,int>;
const int maxN=1e5+10;
LL n,m;
LL a[maxN];
LL ans[maxN];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=n;i++){
		queue<int> q;
		for(int j=i;j<=n;j++){
			bool flag=0;
			int len=q.size();
			for(int k=1;k<=len;k++){
				int t=q.front();q.pop();
				if(flag) continue;
//cout<<t<<' '<<a[j]<<"-----\n";
				if(t==a[j]){
//cout<<"!!!-----------------------------\n";
					flag=1;
				}
				if(!flag) q.push(t);
			}
			q.push(a[j]);
		}
		bool vis[maxN]={};
		while(q.size()){
			int t=q.front();q.pop();
			if(!vis[t]){
				ans[t]++;
				vis[t]=1;
//cout<<i<<' '<<t<<'\n';
			}
		}
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}

