#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;
int n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	srand(time(0));
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		cout<<rand()<<'\n';
	}
	return 0;
}
