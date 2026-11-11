#include <bits/stdc++.h>
using namespace std;
const int N=600000;
long long c,t,n,k;
long long road[N][N];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;i++){
			int x,y;
			cin>>x>>y;
			road[x][y]=1;
		}
		cout<<"Genshin Impact is the best game in the world"<<endl;
	}
}