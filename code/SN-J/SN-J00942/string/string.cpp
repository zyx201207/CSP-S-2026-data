#include <iosteam>
using namespace std; 

int main(){
	string a;
	cin >> a;
	l = a.length;
	int m[l];
	int num;
	for(int i = 0;i < mi;i++){
		cin >> m[i] >> m[i + 1];
	}
	
	for(int j = 1;j <= mi;j++){
		if(a[j] == a[l + 1 - j]){
			break;
		}
		else{
			a[l + 1 - j] = a[j];
			num += 1;
		}
	}
	cout << num;
	return 0;
}