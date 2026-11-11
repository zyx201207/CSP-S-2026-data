#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u[10010],v[10010];
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int t_=1;t_<=t;t_++){
		cin>>n>>k;
		for(int i=1;i<n;i++)cin>>u[i]>>v[i];
		cout<<t_<<'\n';
	}
    return 0;
}

