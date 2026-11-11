#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
string a,b;
char c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	for(int i = 0; i<2; i++){
		a += s1[i];
		b += s2[i];	
	}
	c = s1[2];
	d = s2[2];
	if(c1==c2){
		cout << 1;
	}else{
		cout << "0000";
		return 0;
	}
	if(a==b){
		cout << 1;
	}else{
		cout << "000";
		return 0;
	}
	if(((c=='D'||c=='F')&&(d=='D'||d=='F'))||((c=='A'||c=='B'||c=='C')&&(d=='A'||d=='B'||d=='C'))){
		cout << 1;		
	}else{
		cout << "00";
		return 0;
	}
	if(char(c+1)==d||char(c-1)==d){
		cout << 1;
	}else{
		cout << 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
