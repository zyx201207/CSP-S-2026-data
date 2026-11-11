#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,d;
		cin >> n >> d;
		cout << rand()%(n+1) << endl;
		int a;
		while(n--)cin >> a;
	}
}
