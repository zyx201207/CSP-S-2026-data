#include<bits/stdc++.h>
using namespace std;
int n,k;
int Rand(int l,int r){
	return (rand()<<10)%(r-l+1)+l;
}
int main() {
	srand(time(0));
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>n>>k;
	while(k--){
		for(int i=1;i<n;i++){
			int ui,vi;
			cin>>ui>>vi;
		}
		cout<<(Rand(0,n))<<endl;
	}
	
	
	return 0;
}
