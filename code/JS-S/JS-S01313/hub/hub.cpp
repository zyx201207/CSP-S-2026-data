#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
int c,T,n,k;
int main(){
	freopen("hub5.in","r",stdin);
	//freopen("hub.out","w",stdout);
	cin>>c>>T;
	while(T--){
		cin>>n>>k;
		for(int i=1;i<n;i++){
			int a,b;
			cin>>a>>b;
		}
		int t=(n+1)/2-k+1;
		if(t%4==0){
			cout<<t/4<<"\n";
		}else{
			cout<<t/4+1<<"\n";
		}
	}
	return 0;
}
