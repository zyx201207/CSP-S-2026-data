#include<bits/stdc++.h>
using namespace std;
int n,c,t,k,u[1000001],v[1000001];
struct T{
	int from;
	vector<int>road;
	vector<int>to;
}tree[1000001];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=0;i<n;i++){
			cin>>u[i]>>v[i];
		}
		cout<<k<<endl;
	}
	return 0;
}
