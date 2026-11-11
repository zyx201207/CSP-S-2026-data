#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	srand(time(NULL));
	int t;cin>>t>>t;
	while(t--){
		cout<<rand() % 100000 + 1<<'\n';
	}
	return 0;
}
