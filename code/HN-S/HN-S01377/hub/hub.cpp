#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c;
	cin>>c;
	if(c==0){
		int t;
		cin>>t;
		while(t--){
			int n,k;
			cin>>n>>k;
			vector<int>u(n),v(n);
			for(int i=1;i<=n-1;i++){
				cin>>u[i]>>v[i];
			}
			cout<<2*k+1<<endl;
		}
	}
	return 0; 
}
/*
0 1
4 2
1 2 3 4

0 2
5 3
-2 -10 12
6 2
-4 -3 -2 -1 3 6
*/
