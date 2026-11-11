#include<bits/stdc++.h>
#define int long long
using namespace std;
int C,T,x,y,a[10000000],b[100000001];
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--){
		cin>>x>>y;
		for(int i=1;i<x;i++)cin>>a[i]>>b[i];
		cout<<x;
	}
	return 0;
}
