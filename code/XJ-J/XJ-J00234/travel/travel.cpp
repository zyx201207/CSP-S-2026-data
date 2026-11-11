#include<bits/stdc++.h>
using namespace std;


int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);

    const int MAXN = 10005;

    int a, b;
    string a_, b_, i, j;
    cin >> a >> a_ >> b >> b_;

    if(a == b){
        cout << 1;
    } else {
    	cout << "0000";
    	return 0;
	} 
	if(a_[0] == b_[0] && a_[1] == b_[1]){
		cout << 1;	
	} else {
		cout << "000";
		return 0;
	}
	i = a_[2];
	j = b_[2];
	if(i >= "D" && i <= "E"){
		if(j >= "D" && j <= "E"){
			cout << "11";
			return 0;
		}else{
			cout << "00";
			return 0;
		}
	}
	if(i >= "A" && i <= "C"){
		if(j >= "A" && j <= "C"){
			if(i == "A" || j == "A"){
				if(i == "C" || j == "C"){
					cout << "10";
					return 0;
				} else {
					cout << "11";
					return 0;
				}
			} else {
				cout << "11";
				return 0;
			}
		}else{
			cout << "00";
			return 0;
		}
	}
	cout << "00";
    return 0;
}
