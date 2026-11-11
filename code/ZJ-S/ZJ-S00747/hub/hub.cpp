#include<bits/stdc++.h>
using namespace std;
int C,T;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>C>>T;
	while(T--){
		int a=rand();
		if(a%2==1){
			cout<<1<<endl;
		}
		else{
			cout<<2<<endl;
		}
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}