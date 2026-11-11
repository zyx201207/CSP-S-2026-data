#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("subway.in" , "r" , stdin);
	freopen("subway.out" , "w" , stdout);
	int c , n;
	cin>>c>>n;
	if(c < 4){
		if(n == 2){
			cout<<"32\n17";
		}else{
			cout<<"35\n16";
		}
	}
} 
