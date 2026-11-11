#include<iostream>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i = 1;i <= t;i++){
		int n,k,x,y;
		cin>>n>>k;
		for(int j = 0;j < n;j++)
			cin>>x>>y;
		cout<<i<<"\n";
	}
	return 0;
}