#include <iostream>
using namespace std;
int a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cout<<0;
		return 0;
	}else{
		cout<<1;
		return 1;
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
