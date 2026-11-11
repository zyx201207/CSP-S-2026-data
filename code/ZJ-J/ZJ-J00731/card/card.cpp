#include<bits/stdc++.h>
using namespace std;
int lowbit(int x){
	return x&-x;
}
int n,m,a[500005],ans[300005],t[500005],pre[300005];
pair<int,int>s[500005];
map<int,int>dy;
void add(int x,int k){
	while(x<=n){
		t[x]+=k;
		x+=lowbit(x);
	}
}
int query(int x){
	int res=0;
	while(x){
		res+=t[x];
		x-=lowbit(x);
	}
	return res;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++){
		scanf("%d",&a[i]);
		s[i]={pre[a[i]],i};
		pre[a[i]]=i;
	}
	for(int i=1;i<=m;i++) ans[i]=pre[i];
	sort(s+1,s+n+1);
	for(int i=1;i<=n;i++){
		if(s[i].first==0) continue;
		int bgd=query(s[i].first);
		add(s[i].first,s[i].first-bgd);
		add(s[i].second,bgd-s[i].first);
	}
	for(int i=1;i<=m;i++) ans[i]-=query(pre[i]);
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}