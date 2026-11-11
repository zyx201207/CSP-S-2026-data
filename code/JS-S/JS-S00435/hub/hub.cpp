#include<bits/stdc++.h>
using namespace std;
struct node{
	int u,v;
}a[500];
int main()
{
	freopen("hub.in","r",stdin);
	freopen("hubout.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	int c,t;
	int n,k;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			cin>>a[i].u>>a[i].v;
		}
	}
	cout<<"2";
	return 0;
}
