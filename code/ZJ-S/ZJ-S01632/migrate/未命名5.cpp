#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
int tp,T,n,pre[2000005],nxt[2000005],cnxt[2000005],cpre[2000005];ll w[2000005],d,ans,spre[2000005],snxt[2000005];
int check(int l,int r){
	vector<int>tmp1,tmp2;
	for(int i=l;i<r;i=nxt[i]){
		if(!nxt[i])return 0;
		if(nxt[i]<r)tmp1.emplace_back(nxt[i]);
	}
	for(int i=r;i>l;i=pre[i]){
		if(!pre[i])return 0;
		if(pre[i]>l)tmp2.emplace_back(pre[i]);
	}
	reverse(tmp2.begin(),tmp2.end());
	if(tmp1.size()!=tmp2.size()){
		cout<<"error"<<'\n';return 0;
	}
	for(int i=0;i<tmp1.size();i++){
		if(tmp1[i]!=tmp2[i]){
			for(int j=i+1;j<tmp1.size();j++)if(tmp1[j]!=tmp2[j])return 0;
			cout<<"ok"<<" "<<l<<" "<<r<<" "<<tmp1[i]<<" "<<tmp2[i]<<'\n';
			return 1;
		}
	}
	return 0;
}
void solve(){
	cin>>n>>d;for(int i=1;i<=n;i++)cin>>w[i],pre[i]=nxt[i]=cnxt[i]=cpre[i]=spre[i]=snxt[i]=0;ans=0;
	for(int i=n-1,p=n;i>=1;i--){
		while(w[p]-w[i]>d)p--;
		if(p>i)nxt[i]=p,cnxt[p]++;
	}
	for(int i=2,p=1;i<=n;i++){
		while(w[i]-w[p]>d)p++;
		if(p<i)pre[i]=p,cpre[p]++;
	}
	for(int i=1;i<=n;i++){
		spre[i]=cnxt[i];
		if(nxt[pre[i]]==i)spre[i]+=spre[pre[i]];
	}
	for(int i=n;i>=1;i--){
		snxt[i]=cpre[i];
		if(pre[nxt[i]]==i)snxt[i]+=snxt[nxt[i]];
	}
	for(int i=1;i<=n;i++){
		for(int j=i+3;j<=n;j++){
			ans+=check(i,j);
		}
	}
	cout<<ans<<'\n';
}
signed main(){
	//freopen("migrate3.in","r",stdin);
	//freopen("migrate.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>tp>>T;while(T--)solve();
}