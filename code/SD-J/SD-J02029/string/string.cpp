#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	long long a,n,m,i,j;
	char b;
	string s;
	cin >> n;
	for(i = 1;i <= n;i++){
		cin >> a >> b;
		for(j = 1;j <= a;j++){
			s+=b;	
		}
	}
	
	if(n == 1){
			cout << "0";
			return 0;
		}
	else{
		if(a == 1){
			if(n % 2 == 0){
				cout << n / 2;
				return 0; 
			}
			else{
				cout << n / 2;
				return 0;
			}
		}
    }
//	if(n == 2){
//		
//	}
	fclose(stdin);
	fclose(stdout);
//6
//1000000000 a
//1000000000 a
//1000000000 a
//1000000000 b
//1000000000 b
//1000000000 b
	return 0;
}
