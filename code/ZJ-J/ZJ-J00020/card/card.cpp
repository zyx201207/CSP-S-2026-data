#include<bits/stdc++.h>
using namespace std;
const int maxn=500005;
int n,m,a[maxn],cnt[maxn];
bool vis[maxn];
vector<int>pos[maxn];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)scanf("%d",&a[i]),pos[a[i]].push_back(i);
	vector<int>::iterator it;
	for(int i=1;i<=n;i++){
		memset(vis,1,sizeof(vis));
		for(int j=1;j<=m;j++){
			it=lower_bound(pos[j].begin(),pos[j].end(),i);
			if(it!=pos[j].end()&&it!=pos[j].end()-1)
				for(int k=(*it)+1;k<pos[j].back();k++)vis[a[k]]=0;
		}
		for(int j=1;j<=m;j++){
			if(pos[j].back()>=i)
				cnt[j]+=vis[j];
		}
	}
	for(int i=1;i<=m;i++)printf("%d ",cnt[i]);
	return 0;
}