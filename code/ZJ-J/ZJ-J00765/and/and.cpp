#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[200010],dp[200010];
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
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read(),m=read();
	for(ll i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(ll i=1;i<=n;i++){
		dp[0]=a[i];
		for(ll j=m;j>=1;j--){
			dp[j]=max(dp[j-1]&a[i],dp[j]);
		}
	}
	cout<<dp[m];
	return 0;
}
/*
5 3
31 3 1 15 7

4 2
15 16 7 8
*/
