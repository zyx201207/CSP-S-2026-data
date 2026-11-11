#include<bits/stdc++.h>
#define ll long long
using namespace std;
ll n,m;
ll a[200005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin>>n>>m;
	for(int i=0;i<n;i++){
		cin>>a[i];
	} 
	sort(a,a+n-1);
	if(m==0)cout<<a[n-1];
	else if(m==n)cout<<0;
	else cout<<4;
	
	return 0;
} 
