#include<bits/stdc++.h>
using namespace std;
vector<int>v[100006];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;cin>>c>>t;
	while(t--){
		int n,k;cin>>n>>k;
		for(int i=1;i<n;i++){
			int x,y;cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		int m=(n+1)/2;
		m-=k;m/=4;
		cout<<m+1<<endl;
	}
	return 0;
}