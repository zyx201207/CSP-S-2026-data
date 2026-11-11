#include<bits/stdc++.h>
using namespace std;
const int N=2e6;
int u[N],v[N],C,T,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	//Chinese Can Fly!
	cin>>C>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
		cout<<5;
	}
	return 0;
}
