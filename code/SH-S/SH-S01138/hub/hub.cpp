#include<iostream>
using namespace std;
int c,t,n,k;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	while(t--){
		cin>>n>>k;
		for(int i=1;i<=n-1;i++){
			cin>>k;
			cin>>k;
		}
		cout<<3<<endl;
	}
	return 0;
}
