#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n;
	cin>>n;
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
