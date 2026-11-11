#include<bits/stdc++.h>
#define ac ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define ll long long
using namespace std;
ll n,m;
ll a[5001020];
ll b[5001020];
ll c[3001020];
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ac;
	cin>>n>>m;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		c[a[i]]++;
	}
	for(int i=1;i<=m;i++){
		c[i]=c[i]+c[i-1];
		cout<<c[i]<<' ';
	}
	return 0;
}

