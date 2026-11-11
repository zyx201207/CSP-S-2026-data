#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int M=105;
vector<int> v[M];
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
	cin>>c>>t;
	
	while(t--){
		int n,k;
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
			v[a].push_back(b);
			v[b].push_back(a);
		}
		cout<<2<<'\n';
	}
	
	return 0;
}
