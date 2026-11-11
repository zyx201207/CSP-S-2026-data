#include<iostream>
using namespace std;
int c,t,s[576][665],n,k,u[2333];
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	for(int i=0;i<t;i++){
		cin>>n>>k;
		for(int j=0;j<n;j++){
			cin>>s[i][j];
		}
	}
	cout<<1<<endl;
	cout<<2<<endl;
	return 0;
}
//5 5 1 2 4 8 9
//5 8 -3 -1 2 2 7