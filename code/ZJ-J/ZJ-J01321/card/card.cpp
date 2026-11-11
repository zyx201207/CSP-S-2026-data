#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m,a[500010],b[300010],d,ans[300010],F;
stack<ll> st;
inline ll read(){
	ll s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)) s=s*10+ch-'0',ch=getchar();
	return s*f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();m=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
		if(a[i]<a[i-1]) F=1;
	}
	if(!F){
		for(ll i=1;i<=n;i++){
			for(ll j=a[i];j<=m;j++) ans[j]++;
		}
	}
	else if(m==1){
		printf("%lld",n);
		return 0;
	}
	else if(m==2&&n>5){
		for(ll i=1;i<=n;i++){
			if(a[i]==a[n]) ans[a[i]]++;
			else ans[1]++,ans[2]++;
		}
	}
	else{
		for(ll i=1;i<=n;i++){
			memset(b,0,sizeof(b));
			for(ll j=i;j<=n;j++){
				if(b[a[j]]){
					while(st.size()!=b[a[j]]) b[st.top()]=0,st.pop();
				}
				else b[a[j]]=st.size()+1,st.push(a[j]);
			}
			while(!st.empty()) ans[st.top()]++,st.pop();
		}	
	}
	for(ll i=1;i<m;i++) printf("%lld ",ans[i]);
	printf("%lld",ans[m]);
}
