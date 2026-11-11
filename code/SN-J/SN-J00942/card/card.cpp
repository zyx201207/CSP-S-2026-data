#include <irsteam>
using namespace std;

int main(){
	int m;
	int n;
	cin >> n >> m;           //m zhonglei  n shuliang
	int a[n];
	int x[n];
	for(int i = 1;i <= n;i++){
		cin >> a[i];
	}
	
	for(int j = 1; j <= n;j++){
		for(int l = l; l <= j;l++){
			for(int f = 1; f <= j-l; f++){
				if(a[j-l] == a[j-l+f]){
					x[j-l] = a[j];
				}
				else(){
					x[j-l] = a[j-l];
					x[j] = a[j];
				}
	
			}
		}
	}
	int plus = 0;
	for(int p = 0; p <= m;p++){
		plus == a[p];
		for(int z = 0;z < p;z++){
			if(plus == a[z]){
				plus += 1;
			}
		}
		cout << plus << " ";
	}

	return 0;
}
