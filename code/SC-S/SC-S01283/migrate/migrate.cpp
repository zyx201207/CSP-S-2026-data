#include<bits/stdc++.h>
#include<windows.h>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int c,t;
	cin>>c>>t;
	for(int i=1;i<=t;i++){
		int a=rand()%2;
		if(a){
			cout<<0;
		}
		else{
			int b=rand()%2000000;
			cout<<b;
		}
		cout<<endl;
	}
	fclose(stdin);
	return 0;
}