#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
ll a[500005],ct[300005],b[300005],nxt[500005];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	ll n,m;
	cin>>n>>m;
	for(int i=1;i<=n;i++) cin>>a[i];
	for(int i=1;i<=m;i++) b[i]=-1;
	for(int i=n;i>=1;i--) nxt[i]=b[a[i]],b[a[i]]=i;
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			while(nxt[j]!=-1) j=nxt[j];
			ct[a[j]]++;
		}
	}
	for(int i=1;i<=m;i++){
		cout<<ct[i]<<' ';
	}
} //rp++
