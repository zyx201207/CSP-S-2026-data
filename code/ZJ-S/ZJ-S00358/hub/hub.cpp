#include<iostream>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,_;
	cin>>c>>_;
	while(_--){
		int n,k;
		cin>>n>>k;
		if(k>=n*2/3){
			cout<<1<<endl;
		}else{
			cout<<2<<endl;
		}
	}
}
