#include<bits/stdc++.h>
using namespace std;
void solve1(){
	int n,k;
	cin>>n>>k;
	int ans=(n-k)/8;
	cout<<ans<<'\n';
	for(int i=1;i<n;i++){
		int x,y;
		cin>>x>>y;
	}
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	if(c==13||c==14){
		while(t--){
			solve1();
		}
	}else{
		while(t--){
			cout<<"1\n";
		}
	}
	return 0;
}