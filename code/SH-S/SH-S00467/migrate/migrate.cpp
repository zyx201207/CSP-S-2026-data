#include <iostream>
#include <cstdio>
using namespace std;
int c,p;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>p;
	for(int i=1;i<=p;i++){
		cout<<i<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;	
} 
