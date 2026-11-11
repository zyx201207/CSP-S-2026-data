#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a, b, c, d;
	cin >> a >> b >> c >> d;
	if(a == c){
		cout << "1";
	}else{
		cout << "0000";
		return 0;
	}
	if(b[0] == d[0] && b[1] == d[1]){
		cout << "1";
	}else{
		cout << "000";
		return 0;
	}
	if(int(b[2]) >= d[2]){
		if(b[2] - d[2] <= 6){
			if(b[2] - d[2] == 1){
				if(int(b[2] == 68) && int(d[2] == 67)){
					cout << "00";
			    }else{
			    	cout << "11";
				}
			}else{
				cout << "10";
			}
		}else{
			cout << "00";
		}
	}else{
	    if(d[2] - b[2] <= 6){
			if(d[2] - b[2] == 1){
				if(int(b[2] == 67) && int(d[2] == 68)){
					cout << "00";
			    }else{
			    	cout << "11";
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "00";
		}	
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
