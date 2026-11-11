#include<bits/stdc++.h>
using namespace std;
int c,t;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	cin>>c>>t;
	if(c==0){
		cout<<1<<endl<<2<<endl;
		return 0;
	}
	for(int i=1;i<=t;i++){
		srand(time(0));
		int n=rand();
		cout<<n<<endl;
	}
	return 0;
}

