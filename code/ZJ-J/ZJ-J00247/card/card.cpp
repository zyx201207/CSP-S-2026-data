#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,i,s[300005],j,g[300005],f[300005],l,o;
deque<ll>k[300005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;vector<ll>a(n+1);
	for(i=0;i<n;i++)cin>>a[i],g[a[i]]=i,f[a[i]]++;l=n-1;a[n]=0;
	while(1){
		if(o>=m||l<0)break;
		if(k[a[l]].size()){l--;continue;}
		o++;
		k[a[l]]=k[a[l+1]];k[a[l]].push_front(a[l]);
		for(ll c:k[a[l]])s[c]+=f[a[l]];
		l--;
	}
	for(i=1;i<=m;i++)cout<<s[i]<<' ';
	return 0;
}
