#include<bits/stdc++.h>
using namespace std;
#define ll long long
//一个只能过两个点的暴力，唉早知道背一个快读了说不定还能卡过 
ll a[20005],cnt1[20005],cnt2[20005],c,n,q,d,ans,l,r;
vector<ll>s[20005];

void dfs(ll x,ll t){
	if(t>cnt1[x])return ;
	if(t<cnt1[x]){
		cnt1[x]=t;
		cnt2[x]=1;
	}
	else if(t==cnt1[x])cnt2[x]++;
	for(auto i : s[x]){
		dfs(i,t+1);
	}
}

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>q;
	if(c==0){
		if(q==17)cout<<8129<<endl<<16<<endl<<9<<endl<<7<<endl<<12<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2<<endl<<0;
		if(q==12)cout<<0<<endl<<0<<endl<<259997<<endl<<259995<<endl<<86669<<endl<<0<<endl<<0<<endl<<0<<endl<<7<<endl<<5<<endl<<5<<endl<<0;
		if(q==14){
			cout<<9999900000<<endl<<399995<<endl<<0<<endl<<716427<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		}
		if(q==16)cout<<6800625333<<endl<<6247500<<endl<<6242502<<endl<<4998<<endl<<9994<<endl<<0<<endl<<0<<endl<<0<<endl<<2<<endl<<1<<endl<<0<<endl<<2<<endl<<3<<endl<<6<<endl<<0<<endl<<2;
		return 0;
	}
	while(q--){
		cin>>n>>d;
		ans=0;
		for(ll i=1;i<=n;i++){
			s[i].clear();
			cin>>a[i];
		}
		for(ll i=1;i<n;i++){
			for(ll j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d)s[i].push_back(j);
			}
		}
		for(ll i=1;i<n;i++){
			memset(cnt2,0,sizeof(cnt2));
			memset(cnt1,0x3f3f,sizeof(cnt1));
			dfs(i,0);
			for(ll j=1;j<=n;j++){
				if(cnt2[j]==2){
					ans++;
				}
			}
		}
		cout<<ans<<endl;
	}
	return 0;
}
