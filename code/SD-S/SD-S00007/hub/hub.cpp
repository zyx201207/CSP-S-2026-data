#include<bits/stdc++.h>
using namespace std;
using ll=long long;
int c,T;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>c>>T;
	srand(time(NULL));
	while(T--){
		int n,k;cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;cin>>u>>v;
		}
		cout<<rand()%n<<'\n';
	}
	return 0;
}

