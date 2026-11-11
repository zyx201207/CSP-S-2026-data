#include <bits/stdc++.h>//nmlogn
#include <map>
#include <vector>
#include <stack>
using namespace std;
const int N=5e5+5;
int a[N],n,m,q[N],cnt[N],g[N],cnt1[N];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		memset(g,0x7f,sizeof(g));
		memset(q,0,sizeof(q));
		int t=0;
		for(int j=i;j<=n;j++){
			if(g[a[j]]>t){
				q[++t]=a[j];
				g[a[j]]=t;
			}else t=g[a[j]];
		}
		set<int>s;
		for(int j=1;j<=t;j++)s.insert(q[j]);
		for(auto v:s)cnt[int(v)]++;
	}
	for(int i=1;i<=m;i++)cout<<cnt[i]<<' ';
	return 0;
}
//start 2.4h
//end 2.9h
