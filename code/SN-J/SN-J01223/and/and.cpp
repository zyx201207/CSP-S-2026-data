#include"bits/stdc++.h"
#define ll long long
using namespace std;
struct Node{
	ll id,pr;
};
bool vis[200010];
ll n,m;
ll dans=0,lans=1; 
ll cnt[200010];
ll a[200010];
vector<Node > aans;
void dfs(ll now,ll yi){
	if(yi==m){
		dans=max(lans,dans);
		return ;
	}
	vis[now]=1;
	for(ll i=1;i<=n;i++){
		if(vis[i]) continue;
		else{
			vis[i]=1;
			lans&=a[now];
			dfs(i,yi+cnt[a[i]]);
			vis[i]=0;
		}
	}
	return ;
}
bool cmp(int a,int b){
	return a>b;
}
bool cmp1(Node a,Node b){
	return a.pr>b.pr;
}
int lowbit(int x){
	return x&(-x);
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	cin>>n>>m;
	for(ll i=1;i<=n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}
	if(n==m){
		ll ans=1;
		for(ll i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
	}else if(m==1){
		ll ans=0;
		for(ll i=1;i<=n;i++){
			ans=max(ans,a[i]);
		}
		cout<<ans;
	}else if(m==2){
		ll ans=1;
		for(ll i=1;i<=n;i++){
			for(ll j=i+1;j<=n;j++){
				ans=max((a[i])&(a[j]),ans);
			} 
		}
		cout<<ans;
	}else if(n<=20){
		dfs(1,0);
		cout<<dans;
	}else{
		sort(a+1,a+n+1,cmp);
		ll ans=a[1];
		ll now=a[1];
		for(ll i=1;i<=n;i++){
			ll tmpa=a[i];
			ll tmpb=now;
			ll pr=0;
			while(max(tmpa,tmpb)>0){
				if(lowbit(tmpa)<lowbit(tmpb)){
					pr-=lowbit(tmpa);
					tmpb-=lowbit(tmpb);
				}else if(lowbit(tmpa)>lowbit(tmpb)){
					pr+=lowbit(tmpa);
					tmpa-=lowbit(tmpa);
				}else{
					tmpa-=lowbit(tmpa);
					tmpb-=lowbit(tmpb);
				}
			}
			aans.push_back({i,pr});
		}
		sort(aans.begin(),aans.end(),cmp1);
		ll sz=aans.size();
		for(ll i=sz;i>=0;i--){
			m-=cnt[a[aans[i].id]];
			ans+=aans[i].pr;
			if(m==0){
				break;
			}
		}
		cout<<ans;
	}
	return 0;
}
