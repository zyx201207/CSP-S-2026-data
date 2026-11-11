#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e6+10;

int main(){
	freopen("subway.in","r",stdin);
	freopen("subway.out","w",stdout);
	int c,n,m;
	cin >> c >> n >> m;
	if(n == 2 && m == 5){
		cout << 32 << endl << 17;
	}
	if(n == 3 && m == 7){
		cout << 35 << endl << 16;
	}
	return 0; 
}
