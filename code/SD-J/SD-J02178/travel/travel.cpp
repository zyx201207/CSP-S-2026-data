#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string Rc,Rs,Xc,Xs;
	cin >> Rc >> Rs >> Xc >> Xs;
	
	//1.同一车厢
	if(Rc != Xc){
		cout << "0000";
		return 0;
	}else{
		cout << "1";
	}
	
	//2.同一排
	if(Rs[0] != Xs[0] || Rs[1] != Xs[1]){
		cout << "000";
		return 0;
	}else{
		cout << "1";
	}
	
	//3.同一侧
	bool Rce,Xce;
	if(Rs[2] == 'A' || Rs[2] == 'B' || Rs[2] == 'C'){
		Rce = 0;
	}else{
		Rce = 1;
	}
	
	if(Xs[2] == 'A' || Xs[2] == 'B' || Xs[2] == 'C'){
		Xce = 0;
	}else{
		Xce = 1;
	}
	
	if(Rce != Xce){
		cout << "00";
		return 0;
	}else{
		cout << "1";
	}
	
	//4.相邻
	if(Rce == 1 && Xce == 1){  //只有一种(D,F) 
		cout << "1";
	}else{
		if(Rs[2] == 'B' || Xs[2] == 'B'){
			cout << "1";  //(A,B)  (B,C)  只要有B 
		}else{
			cout << "0";
		}
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
