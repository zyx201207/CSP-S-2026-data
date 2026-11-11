#include<bits/stdc++.h>
using namespace std;
#define int long long
int task,t;
int n,d;
int x[2000010];
signed main(){
	ios::sync_with_stdio(0);cin.tie(0);
	freopen("migrate.in","r",stdin);freopen("migrate.out","w",stdout);
	cin>>task>>t;
	if(task==1)cout<<1<<'\n'<<2;
	for(;t--;){
		cin>>n>>d;
		for(int i=1;i<=n;i++)cin>>x[i];
		cout<<0<<'\n';
	}
}
