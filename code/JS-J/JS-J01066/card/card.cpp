#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[1000005];
int main(){
	 
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>a[i];
	while(n--)cout<<a[n]<<" ";
	
	 
	return 0;
}

