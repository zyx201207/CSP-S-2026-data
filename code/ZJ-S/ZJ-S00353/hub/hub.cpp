#include<bits/stdc++.h>
using namespace std;

int c,t;

int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n,k;
		cin>>n>>k;
		int u,v;
		for(int i =1;i<n;i++){
			cin>>u>>v;
		}
		cout<<abs(u-v)*n;
	}
}
