#include<bits/stdc++.h>
using namespace std;
int main(){
	fropen("travel.in","r",stdin);
	fropen("travel.out","w",stdout);
	string d,f;
	int a,s,g,h;
	cin >> a >> s >> d >> g >> h >> f;
	if(a == g){
		cout << "1";
	}
	else{
		cout << "0000";
		return 0;
	}
	if(s == h){
		cout << "1";
	}
	else{
		cout << "000";
		return 0;
	}
	if(d == "A"){
		if(f =="B" || f == "C"){
			cout << "1";
		}else{
		cout << "00";
		return 0;
		}
	}
	else if(d == "B"){
		if(f =="A" || f == "C"){
     		cout << "1";
		}
		else{
		cout << "00";
		return 0;
		}
	}
	else if(d == "C"){
		if(f == "B" || f == "A"){
			cout << "1";
		}
		else{
		cout << "00";
		return 0;
		}
	}
	else if(d == "D" && f == "F"){
		cout << "1";
	}
	if(d == "A" && f == "B"){
		cout << "1";
	}
	else if(d == "B" && f == "A"){
		cout << "1";
	}
	else if(d == "B" && f == "C"){
		cout << "1";
	}
	else if(d == "C" && f == "B"){
		cout << "1";
	}
	else if(d == "D" && f == "F"){
		cout << "1";
	}
	else{
		cout << "0";
	} 
	return 0;
}
