#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m,a[500005],s[500005];
bool ck(int q){
	for(int i=1;i+q-1<=n;i++)
		if(a[i+q-1]*(q-1)-s[i+q-2]+s[i-1]<=m)return 1;
	return 0;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++)s[i]=s[i-1]+a[i];
	int l=1,r=n;
	while(l<r){
		if(ck((l+r+1)/2))l=(l+r+1)/2;
		else r=(l+r+1)/2-1;
	}cout<<l;
}
