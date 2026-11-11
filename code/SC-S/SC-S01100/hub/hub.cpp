#include<bits/stdc++.h>
using namespace std;
void solveA(int t){
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;
			cin>>x>>y;
		}int o=(n/2-k+3)/4;
		cout<<o+1<<'\n';
	}
	
}
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	solveA(t);
}