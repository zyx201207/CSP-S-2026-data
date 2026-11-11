#include<bits/stdc++.h>
using namespace std;

using ll=long long;

ll read(){
	ll ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return ret*f;
}

int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ll n=read(),m=read();
	vector<ll> cards(n+1);
	for(int i=1;i<=n;i++) cards[i]=read();
	vector<ll> ans(m+1,0);
	for(int i=1;i<=n;i++){
		vector<ll> now;
		for(int j=i;j<=n;j++){
			ll pos=-1,val=cards[j];
			for(int k=0;k<now.size();k++){
				if(now[k]==val){
					pos=k;
					break;
				}
			}
			while(pos!=-1&&now.size()>pos) now.pop_back();
			now.push_back(val);
//			for(auto& x:now) cout<<x<<' ';
//			cout<<'\n';
		}
//		cout<<'\n';
		vector<bool> ishr(m+1,0);
		for(int j=0;j<now.size();j++) ishr[now[j]]=1;
		for(int j=1;j<=m;j++) ans[j]+=ishr[j];
	}
	for(int i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}