#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	int n;
	cin >> n;
	int a[1005];
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			a[i]+=j;
		}
		cout << a[i];
	}
	fclose(stdin);
	fclose(stdout);

	return 0;
	
}
