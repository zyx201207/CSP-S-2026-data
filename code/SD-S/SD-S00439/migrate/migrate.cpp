#include<iostream>
#include<cstdio>
#include<cstdlib>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		cout<<rand()%10<<endl;
	}
	return 0;
}
