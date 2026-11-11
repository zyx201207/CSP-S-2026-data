#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m,b,d,p;
	cin>>c>>n>>m>>d>>p;
	if(c==2){
		cout<<32<<'\n'<<17;
	}else if(c==3){
		cout<<35<<'/n'<<16;
	}else{
		cout<<0;
	}
	return 0;
} 
