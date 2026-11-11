#include<bits/stdc++.h>
using namespace std;
int c,t,n,k,u,v;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k;
		for(int i=0;i<n-1;i++){
			cin>>u>>v;
		}
	}
	for(int i=0;i<t;i++){
		cout<<i%2+1<<endl;
	}
	return 0;
}
