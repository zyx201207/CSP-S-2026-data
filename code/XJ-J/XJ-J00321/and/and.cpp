#include<bits/stdc++.h>
using namespace std;
int n,m,ans;
int a[200005];
void dfs(int step,int cnt,int now){
	if(cnt>m){
		cerr<<now<<" ";
        ans=max(ans,now);
		return; 
	}
	else if(step>n)  return;
	dfs(step+1,cnt,now);
	dfs(step+1,cnt+1,(now&a[step]));
}
bool cmp(int d,int e){
	bitset<32> b((unsigned long long)d);int cntf=0;
	for(int i=0;i<32;i++)  if(b[i])  cntf++;
	bitset<32> bb((unsigned long long)e);int cnts=0;
	for(int i=0;i<32;i++)  if(bb[i])  cnts++;
	return cntf>cnts;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cin>>n>>m;
	for(int i=1;i<=n;i++)  cin>>a[i];
	if(m==1){
		int maxx=-1;
		for(int i=1;i<=n;i++)  maxx=max(maxx,a[i]);
		cout<<maxx;
	}
	sort(a+1,a+1+n,cmp);
	int ans=a[1];
	for(int i=2;i<=m;i++){
		ans&=a[i];
		cerr<<ans<<" ";
	}
	cout<<ans;
	cerr<<ans;
	return 0;
}