#include <bits/stdc++.h>
using namespace std;
int main(){
	fecopen("travel.in","r",stdin);
	fecopen("travel.out","w",stdout);
	int c1,c2;
	char s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c2 == c1){
		cout << 0;
	}
	else{
		cout << 1;
	}
	if(int(s1) = int(s2)){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if('s1'-'s2'<=2){
		cout << 1;
	}
	else{
		cout << 0;
	}
	if('s1'-'s2'==0){
		cout << 0;
	}
	else{
		cout << 1;
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
