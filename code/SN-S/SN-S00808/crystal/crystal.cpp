#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w"stdout);
	long long int n,m;
	cin >> n >> m;
	cout << n << m << endl;
	int a[n];
	for(int i = 1;i <= n;i++) cin >> a[i];
	for(int i = 1;i <= m;i++){
		int max = a[1],min = a[0];
		int dax = 1;
		int room;
		while (1){
			if (dax <= n){
				if (min < max){
					max = min;
					room = dax;
					min = a[dax];
					dax++;
				}
				else{
					min = a[dax];
					dax++;//指针计数 
				}
   			}
			else{
				break;
			}
		a[room]++;//增加最小值 
		}
	}
	long long int fooy = a[0];
	long long int fooe = a[1];
	long long int y = 1;
	long long int e = 2;
	long long int noom = 0;
	for(int i = 1;i <= n;i++){
		for(int j = 0;j <= n;j++){ //111
			if (fooy == fooe){
				noom++;
				fooe = a[e];
			}
		}
		fooy = a[y];
		y++;
	}
	cout << noom;
}

