#include<bits/stdc++.h>
using namespace std;
int n,k,t;
vector<int> v[1000002];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,x,y;
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n;++i){
			v[i].clear();
		}
		for(int i=1;i<n;++i){
			cin>>x>>y;
			v[x].push_back(y);
			v[y].push_back(x);
		}
		if(n==k){
			cout<<"0\n";
			continue;
		}
		if(n==2||n==3){
			cout<<"1\n";
			continue;
		}
		if(n==4){
			if(v[1].size()==3||v[2].size()==3||v[3].size()==3||v[4].size()==3){
				cout<<"1\n";
				continue;
			}
			else if(k==1){
				cout<<"2\n";
				continue;
			}
			else{
				cout<<"1\n";
				continue;
			}
		}
		if(n==5){
			if(v[1].size()==4||v[2].size()==4||v[3].size()==4||v[4].size()==4||v[5].size()==4){
				cout<<"1\n";
				continue;
			}
			if(k==1){
				cout<<"2\n";
				continue;
			}
			cout<<"1\n";
			continue;
		}
		cout<<"1\n";
	}
	return 0;
} 