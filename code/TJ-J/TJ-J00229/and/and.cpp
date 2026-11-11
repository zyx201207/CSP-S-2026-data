#include <iostream>
using namespace std;
int main{
	freopen("and.in","r",stdin); 
	freopen("and.out","w",stdout);
	int n;
	int m;
	cin >> n >> m;
	int a[n];
	for(int i=1;i<=n;i++){
		cin >> a[i];
	}
	int maxx=0;
	int b;
    for(int i = 1; i <= n;i++){
    	b=a[i]|a[i+1];
    	if(maxx<a){
    		maxx=a;
		}
	}
	cout << maxx;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
