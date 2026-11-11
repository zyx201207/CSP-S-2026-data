#include <bits/stdc++.h>
#include <string>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a;
    string b;
    string c;
    string d;
    bool e = true;
    bool f = false;
    cin >> a >> b >> c >> d;
    if(a[0] == c[0] && a[1] == a[1]){
        cout << '1';
    }
    else{
    	cout << '0';
	}
    for(int i = 0;i < 2;i++){
        if(b[i] != d[i]){
            e = false;
        }
    }
    if(e){
        cout << '1';
    }
    else{
    	cout << '0';
	}
	if('A'<= b[2] <= 'C' && 'A' <= d[2] <= 'C'){
		f = true;
	}
	else if('D' <= b[2] <= 'F' && 'D' <= d[2] <= 'F'){
		f = true;
	}
	if(f){
		cout << '1';
	}
	else{
		cout << '0';
	}
	if(b[2] - 1 == d[2] || d[2] - 1 == b[2]){
		cout << '1';
	}
	else{
		cout << '0';
	}
    
}

