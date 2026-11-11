#include<bits/stdc++.h>
using namespace std;
struct ticket{
	int x;
	string z;
};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ticket a,b;
	string ans;
	cin >> a.x >> a.z >> b.x >> b.z;
	if(a.x==b.x){
		//pass
	}
	else{
		cout << "0000";
		return 0;
	}
	if(a.z[0]+a.z[1] == b.z[0]+b.z[1]){
		//pass
	}
	else{
		cout << "1000";
		return 0;
	}
	if(a.z[2]=='A'){
		if(b.z[2]=='B') {//pass 
		}
		else if(b.z[2]=='C'){cout << "1110";return 0;} 
		else {cout << "1100";return 0;}
	}
	else if(a.z[2]=='B'){
		if(b.z[2]=='A'||b.z[2]=='C') {//pass 
		} 
		else {cout << "1100";return 0;}
	}
	else if(a.z[2]=='C'){
		if(b.z[2]=='B') {//pass 
		}
		else if(b.z[2]=='A'){cout << "1110";return 0;} 
		else {cout << "1100";return 0;}		
	}
	else if(a.z[2]=='D'){
		if(b.z[2]=='F') {//pass 
		} 
		else {cout << "1100";return 0;}}
	else{
		if(b.z[2]=='D') {//pass 
		} 
		else {cout << "1100";return 0;}
	}
	cout << "1111";
	fclose(stdin);
	fclose(stdout);
	return 0;
}