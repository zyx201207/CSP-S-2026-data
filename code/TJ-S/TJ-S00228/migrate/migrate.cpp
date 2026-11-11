#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen(" migrate.in","r",stdin);
	freopen(" migrate.out","w",stdout);
	int n,d,u,v, c,t;
	cin >> c >> t >> n >> d >> u >> v;
	for(int i<=0;i<=n;i++){
		for(int j<=0;j<=n;j++){
			if(i-j<=d){
				cout << 1<< endl;
			}else{
				cout << 2<< endl;
			}
		}
	}
}

