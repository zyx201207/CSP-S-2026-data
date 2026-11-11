#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main(){
	freopen("crystal.in","w",stdout);
	srand(time(0));
	int n=rand()%10,m=rand()%10;
	while(n==0)n=rand()%10;
	cout<<n<<' '<<m<<"\n";
	for(int i=1;i<=n;i++){
		int a=rand()-rand();
		cout<<a<<"\n";
	}
	return 0;
}
