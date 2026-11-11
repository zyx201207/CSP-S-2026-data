#include<bits/stdc++.h>
#define ll long long
using namespace std;
int c,t;

int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin >> c >> t;
	if(c==11||c==12){
		while(t--){
			int n,d,a,b;
			cin >> n >> d >> a >> b;
			int x = 0;
			x = b-a;
			if(d<x){
				cout << 0 << endl;
			}else{
				cout << 1 << endl;
			}
		}
	}else{
		while(t--){
			cout << 0 << endl;
		}
	}
	return 0 ;
}

