#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out ","w",stdout);
	string a,b;
	string c,d;
	cin >> a >> b >> c >> d;
	string zw1[10];
	string zw2[10];
	string cx1[10];
	string cx2[10];
	for(int i = 0;i < 3;i++){
		cx1[i] = a[i];
		cx2[i] = c[i]; 
	}
	string zm[6] = {"A","B","C","D","E","F"};
	int sz[6] = {1,2,3,4,5,6};
	for(int i = 0;i < 3;i++){
		zw1[i] = b[i];
		zw2[i] = d[i];
	}

	cout<<endl;
	int s1,s2;
	for(int i = 0;i < 6;i++){
		for(int j = 0;j < 6; j++){
			if(zw1[2]  == zm[i]){
				s1 = sz[i];
			}
			if(zw2[2]  == zm[i]){
				s2 = sz[i];
			}
		}
	}
	
	
	
//	for(int i = 0;i < 3;i++){
//		cout <<zw1[i];
//	}
//	cout<<endl;
//	for(int i = 0;i < 3;i++){
//		cout <<zw2[i];
//	}
//	cout<<endl;
	
	
	
	
	int a1,a2;
	for(int i = 0;i < 18;i++){
		if(zw1[0] == "0"){
			a1 = 0;
		}
		else{
			a1 = 10;
		}
		if(zw2[0] == "0"){
			a2 = 0;
		}
		else{
			a2 = 10;
		}
		//a1
		if(zw1[1] == "0"){
			a1 += 0;
		}
		if(zw1[1] == "1"){
			a1 += 1;
		}
		if(zw1[1] == "2"){
			a1 += 2;
		}
		if(zw1[1] == "3"){
			a1 += 3;
		}
		if(zw1[1] == "4"){
			a1 += 4;
		}
		if(zw1[1] == "5"){
			a1 += 5;
		}
		if(zw1[1] == "6"){
			a1 += 6;
		}
		if(zw1[1] == "7"){
			a1 += 7;
		}
		if(zw1[1] == "8"){
			a1 += 8;
		}
		if(zw1[1] == "9"){
			a1 += 9;
		}
		//a2
		if(zw2[1] == "0"){
			a2 += 0;
		}
		if(zw2[1] == "1"){
			a2 += 1;
		}
		if(zw2[1] == "2"){
			a2 += 2;
		}
		if(zw2[1] == "3"){
			a2 += 3;
		}
		if(zw2[1] == "4"){
			a2 += 4;
		}
		if(zw2[1] == "5"){
			a2 += 5;
		}
		if(zw2[1] == "6"){
			a2 += 6;
		}
		if(zw2[1] == "7"){
			a2 += 7;
		}
		if(zw2[1] == "8"){
			a2 += 8;
		}
		if(zw2[1] == "9"){
			a2 += 9;
		}
	}

	if(a == c){
		cout << 1;
	}
	else{
		cout<< 0;
	}

	if(a1 == a2){
		cout << 1;
	}
	else{
		cout << 0;
	}

	if(s1 <= 4){
		if(s2 <= 4){
			cout<< 1;
		}
		else{
			cout << 0;
		}
	}
	else if(s1>4){
		if(s2>4){
			cout<< 1;
		}
		else{
			cout << 0;
		}
	}
	else{
		cout << 0;
	}

  
	if(s1 == s2 +1 || s1 == s2-1){
		cout << 1;
	}
	else{
		cout << 0;
	}
	 
	return 0;
}
