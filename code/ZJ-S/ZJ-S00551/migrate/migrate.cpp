#include<bits/stdc++.h>
using namespace std;
long long r[2000002];
int main(){
	int a,b;
	cin>>a>>b;
	while(b--){
		int c,d;
		cin>>c>>d;
		for(int i=1;i<=c;++i)cin>>r[i];
		if(c==1){
			cout<<0<<endl;
			continue;
		}
		if(c==2){
			cout<<0<<endl;
			continue;
		}
		if(c==3){
			cout<<0<<endl;
			continue;
		}
		if(r[3]-r[1]>d){
			cout<<0<<endl
			continue;
		}
		if(r[3]-r[1]<=d){
			cout<<c-3<<endl;
		}
		if
	}
	
	return 0;
}
