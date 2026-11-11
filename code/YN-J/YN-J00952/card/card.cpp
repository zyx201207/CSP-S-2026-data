#include <iostream>
#include <vector>
using namespace std;

size_t n, m;
int e1, e2;

int main(){
//	cout << "-- Debug --" << endl << "-- Remember to change file read and write --" << endl << endl;
	
	freopen("card.in", "r", stdin);
	freopen("card.out", "w", stdout);
	
	cin >> n >> m >> e1 >> e2;
	
	// lol.
	for (size_t i = 0; i < m; i++) {
		int idk;
		idk = (e1 * i / e2 + n * m * e2 + i * i) % 10;
		cout << idk << " ";
	}
	
	return 0;
}
