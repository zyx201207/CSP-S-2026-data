#include <bits/stdc++.h>
using namespace std;
int main(){
	int a,b;
	srand(time(0));
	
	cin>>a>>b;
	while(b--){
		cout<<rand()%100000+1<<endl;
	}
	return 0;
} 
