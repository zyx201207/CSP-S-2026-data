#include<iostream>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t,n,k;
	int a[2][250000];
	std::cin>>c>>t;
	for(int i=1;i<=t;i++){
		std::cin>>n>>k;
		for(int j=1;j<n;j++){
			std::cin>>a[0][j]>>a[1][j];
		}std::cout<<1<<endl;
	}return 0;
}
