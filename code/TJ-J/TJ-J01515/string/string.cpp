#include <iostream>
#include <cmath>
using namespace std;
int main()
{
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	
	string hui[1000] = {};
	string a;
	int n,j,cnt1 = 0;
	cin >> n;
	for(int i = 1;i <= n;i++){
		cin >> j >> a;
		cnt1 = cnt1+j;
		for(int z = 0;z < j;z++){
			hui[z] = a;
		}
	}
	if(cnt1 % 2 == 1){
		int q = ceil(cnt1/2);
		for(int y = q;y < cnt1;y++){
			int c = 2;
			hui[y] = hui[y-2];
			c +=1;
		}
	}
	for(int v = 0;v<cnt1;v++){
		cout << hui[v];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
