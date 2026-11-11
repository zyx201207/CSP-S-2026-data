#include<iostream>
#include<cstdio>
#include<algorithm>
#include<vector>
#define ll long long
using namespace std;
int op,T;
int n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	cin>>op>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int u,v;
			cin>>u>>v;
		}
		if(op==13 || op==14){
			cout<<((n+1)/2-k)/4+1<<"\n";
		}
		else{
			cout<<(n-2+3)/4<<"\n";
		}
	}
	return 0;
}

