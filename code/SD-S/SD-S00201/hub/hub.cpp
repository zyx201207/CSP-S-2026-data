#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
int main(){
	//freopen("hub.in","r",stdin);
	//freopen("hub.out","w",stdout);
	int c,t,n,m;
	cin>>c>>t;
	for(int i=0;i<t;++i){
		cin>>n>>m;
		if(n<=5) cout<<1<<endl;continue;
		if(n>5&&n<=10) cout<<2<<endl; continue;
		if(m==2) cout<<1<<endl;continue;
	}


	return 0;
}

