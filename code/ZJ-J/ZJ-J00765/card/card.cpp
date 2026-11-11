#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500010],last[300010],ans[300010];
ll read(){
	ll f=1,cnt=0;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		cnt=cnt*10+ch-'0';
		ch=getchar();
	}
	return f*cnt;
}
void sl(ll op){
	ll l=op;
	while(l<=n){
		ans[a[l]]++;
		l=last[a[l]]+1;
	}
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read(),m=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
		last[a[i]]=i;
	}
	for(ll i=1;i<=n;i++){
		sl(i);
	}
	for(ll i=1;i<=m;i++) cout<<ans[i]<<' ';
	return 0;
}
/*
4 3
1 2 1 3
*/
