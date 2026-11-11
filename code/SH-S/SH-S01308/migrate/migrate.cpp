#include<iostream>
#include<cstdio>
#include<algorithm>
using namespace std;
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	int num,T;
	cin>>num>>T;
	while(T--){
		cout<<T%2==0?1:0;
	}
	return 0;
}  
