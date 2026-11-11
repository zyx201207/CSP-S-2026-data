#include<bits/stdc++.h>
using namespace std;
const int N=5e5+5;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	int c,t,n,m,x,y;
	int cnt;
	cin>>c>>t;
	while(t--){
		cin>>n>>m;
		for(int i=1;i<=n;i++){
			cin>>x>>y;
		}
		cnt++;
		cout<<cnt<<"\n";
	}
	return 0;
}
