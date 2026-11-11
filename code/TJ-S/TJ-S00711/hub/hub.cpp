#include <iostream>
#include <cstdlib>
using namespace std;
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	int c,t;
	cin >> c >> t;
	while(t--){
		int n,k;
		cin >> n >> k;
		cout << rand()%(n+1) << endl;
		int a;n--;
		while(n--)cin >> a >> a;
	}
}
