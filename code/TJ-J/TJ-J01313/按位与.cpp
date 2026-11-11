#include <iostream>
using namespace std;
int n,m;
int main(){
	cin >> n >> m;
	reopen("and.in","r",stdin);
	reopen("and.out","w",stdout);
	if(n==m){
		cout << m+n;
	}
	return 0;
}
