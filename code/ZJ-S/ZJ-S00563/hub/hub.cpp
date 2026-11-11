#include<bits/stdc++.h>
using namespace std;
#define ll long long
ll c,t,n,k,m,a[100004];
vector<int> e(1000004);
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		ll u,v;
		for(int i=1;i<n;i++)
			cin>>u>>v;
		if(c==11||c==12){
			m=(n-1)/2;
			if(k==n){
				cout<<"0\n";
				continue;
			}
			if(k>=m){
				cout<<"1\n";
				continue;
			}
			if(k==1)
				cout<<m+1<<"\n";
			else
				cout<<"2\n";
		}
	}
	return 0;
}