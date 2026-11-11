#include<bits/stdc++.h> 
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int c1,s1,c2,s2;
	int pai1=0,pai2=0;
	int zuowei[5][18];
	cin >> c1 >> s1 >> c2 >> s2; 
	for(int i=1;i<=17;i++){
		if(c1==1||c1==16 && c2==1||c2==16) continue;
	}
	for(int i=0;i<=17;i++){ 
		if(c1=c2) cout << 1;
		else cout << 0;
	} 
	for(int i=1;i<=18;i++){
		pai1=s1;pai2=s2;
		if(c1==c2&&pai1==pai2) cout << 1;
		else cout << 0; 
	} 
	for(int i=1;i<=5;i++){
		if(s1==s2||s2==s1) cout << 1;
		else cout << 0;
	}
	return 0;
} 
