#include<bits/stdc++.h>
#include<vector>
using namespace std;
int a[500010],n,m,ans[300010],pos[300010];
vector<int> q;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>n>>m;
	for(int i=0;i<n;i++) cin>>a[i];
	for(int i=0;i<n;i++){
		memset(pos,-1,sizeof(pos));
		q.clear();
		for(int j=i;j<n;j++){
			if(pos[a[j]]>0) q.erase(q.begin()+pos[a[j]]-1,q.end());
			q.push_back(a[j]),pos[a[j]]=q.size();}
		for(int j=0;j<q.size();j++) ans[q[j]]++;}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;}
