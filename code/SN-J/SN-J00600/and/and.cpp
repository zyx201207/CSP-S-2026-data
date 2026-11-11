#include <iostream>
#include <cstdio>
using namespace std;
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	int n,m;
	cin >>n>>m;
	int a[n];
	for(int i=0;i<=n-1;i++){
		cin >>a[i];
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
