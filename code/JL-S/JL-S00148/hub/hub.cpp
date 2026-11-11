#include<bits/stdc++.h>
#define ll long long
using namespace std;
bool a[2000005][2000005],b[2000005];
ll c=0,t=0,n=0,k=0,mi=2000005,ma=0,s[2000005],ss[2000005],key=0,ltk=0,value=0;
vector <ll>ans;
bool you(ll x){
	for(ll i=1;i<=k;i++){
		if(x==ss[i])return 1;
	}
	return 0;
}
void bfs(ll arr[2000005],ll m){
	ll _arr[2000005]={0},len=0;
	for(ll i=1;;i++){
		if(you(arr[i])){
			ma=max(ma,m);
			return;
		}
		b[arr[i]]=1;
		for(ll j=1;j<=n;j++){
			if(a[arr[i]][j]&&!b[j]){
				len++;
				_arr[len]=j;
			}
		}
	}
	if(len==0)return;
	bfs(_arr,m+1);
	return;
}
void bfs1(ll arr[2000005]){
	ll _arr[2000005]={0},len=0;
	for(ll i=1;;i++){
		if(arr[i]==0)break;
		b[arr[i]]=1;
		for(ll j=1;j<=k;j++){
			if(a[arr[i]][ss[j]]){
				len++;
				key=1;
				_arr[len]=ss[j];
			}
		}
		if(key==0&&len==0){
			value=1;
			return;
		}
		key=1;
	}
	if(len==0){return;}
	bfs1(_arr);
	return;
}
bool Is(){
	ltk=0;
	memset(b,0,sizeof(b));
	for(ll i=1;i<=k;i++){
		if(!b[i]){
			value=0;key=0;
			ll sma[2000005]={0};
			sma[1]=i;
			bfs1(sma);
			if(value==0){
				ltk++;
				if(ltk>=3){
					return 0;
				}
			}
		}
	}
	return 1;
}
void xuan(ll d,ll l,ll kk){
	if(l>=n-kk)return;
	if(kk==0){
		memset(ss,0,sizeof(ss));
		for(ll i=1;i<=d-1;i++){
			ss[i]=s[i];
		}
		sort(ss,ss+d);
		if(Is()){
			for(int p=1;p<=n;p++){
				ma=0;
				ll sma[2000005]={0};
				memset(b,0,sizeof(b));
				sma[1]=p;
				bfs(sma,0);
				mi=min(mi,ma);
			}
		}
		return ;
	}
	for(ll i=l;i<=n;i++){
		s[d]=i;
		xuan(d+1,i,kk-1);
		s[d]=0;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ans.push_back(0);
	cin>>c>>t;
	c=t;
	while(t>=1){
		n=0;k=0;mi=0;
		memset(a,0,sizeof(a));
		memset(s,0,sizeof(s));
		cin>>n>>k;
		for(ll i=1;i<=n;i++){
			ll aa=0,b=0;
			cin>>aa>>b;
			a[aa][b]=1;
			a[b][aa]=1;
		}
		xuan(1,1,k);
		ans.push_back(mi);
		t--;
	}
	for(ll i=1;i<=c;i++){
		cout<<ans[i]<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
