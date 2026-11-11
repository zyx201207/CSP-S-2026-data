#include<bits/stdc++.h>
using namespace std;
signed main(){
	freopen("test.txt","w",stdout);
	int T=1e4;cout<<"0 "<<T<<"\n";
	mt19937 rd(time(0));
	while(T--){
		int n=rd()%15+2,k=rd()%(n-1)+2;
		cout<<n<<" "<<k<<"\n";
		for(int i=1;i<n;i++) cout<<rd()%i+1<<" "<<i+1<<"\n";
	}
	return 0;
}