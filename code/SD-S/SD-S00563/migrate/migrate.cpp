#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	srand(time(0));
	int c,t;
	cin>>c>>t;	
	while(t--) 
		cout<<(rand()%65536)*(rand()%65536)<<"\n";
	return 0;
}

