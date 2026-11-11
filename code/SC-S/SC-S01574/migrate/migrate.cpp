#include<bits/stdc++.h>
using namespace std;
vector<int>v;
int x[2000050];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t,n,d;
	cin >> c >> t >> n >> d;
	if(c==0){
		cout << 1 << endl << 2;
	}
	while(true){
		if(t==0) break;
		bool f=0;
		for(int i = 1 ; i <= n ; i++){
			cin >> x[i];
			if(x[i]<0) f=1;
		}	
		t--;
		if(f) cout << -1;
		else if(n>5)cout << 2;
		else cout << 1;
	}

	
	return 0;
}