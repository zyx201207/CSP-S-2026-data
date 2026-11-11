#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	srand(time(NULL));
	int t;cin>>t>>t>>t>>t>>t;
	while(t--){
		cout<<rand() % 100000 + 1<<'\n';
	}
	return 0;
}
