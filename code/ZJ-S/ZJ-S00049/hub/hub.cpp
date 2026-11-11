#include<bits/stdc++.h>
using namespace std;
void tezhenA(){
	int n,k;
	cin>>n>>k;
	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
	}
	if(k>=n){
		cout<<0<<endl;
		return;
	}
	if(k>=n/2){
		cout<<1<<endl;
		return;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c;
	cin>>c;
	if(c==13||c==14){
		int _;
		cin>>_;
		while(_--){
			tezhenA();
		}
	}else{
		int _;
		cin>>_;
		while(_--){
			int n,k;
			cin>>n>>k;
			if(k>=n){
				cout<<0<<endl;
			}else{
				cout<<1<<endl;
			}
		}
	}
	return 0;
}
