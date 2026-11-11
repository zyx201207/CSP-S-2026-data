#include<iosteam>
using namespace std;

int main(){
	freopen("travel.in","r","std.in");
	freopen("travel.out","w","std.out");
	int n,m,a[100000],x = 1,b[5000];
	cin >> n >> m;
	for(imt int i = 1;;i++){
		cin >> a[i];
		if(a[i] = 0)
			break;
	}
	for(int j = 1;j <= n;j++){
		for(int i = 1;;i++){
			if(a[i] == a[x]){
				while(x+1 == i){
					a[x] = 0;
					x++;
				}
			b[a[i]]++;
			}
			if(a[i] == 0){
				break;
			}
		}
	}
	for(int l = 1;l <= m;l++)
		cout << b[l];
	return 0;
}