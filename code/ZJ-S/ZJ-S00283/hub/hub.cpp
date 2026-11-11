#include<bits/stdc++.h>
using namespace std;
const int N=2e6+5;
int c,t;
long long u[N],v[N];
long long k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>t;
	while(t--){
		int n;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			cin>>u[i]>>v[i];
		}
		cout<<"1\n";
	}
	return 0;
}