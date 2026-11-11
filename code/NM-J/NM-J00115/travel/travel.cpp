#include<bits/stdc++.h>
using namespace std;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    string ca,sa,cb,sb;
    cin >> ca >> sa >> cb >> sb;
    if(ca == cb){
        cout << 1;
    }else{
        cout << 0 << 0 << 0 << 0;
        return 0;
    }
    if(sa[0] == sb[0] && sa[1] == sb[1]){
        cout << 1;
    }else{
        cout << 0 << 0 << 0;
        return 0;
    }
    if((sa[2] == 'A' && sb[2] == 'B') || (sa[2] == 'B' && sb[2] == 'A') || (sa[2] == 'B' && sb[2] == 'C') || (sa[2] == 'C' && sb[2] == 'B') || (sa[2] == 'D' && sb[2] == 'F') || (sa[2] == 'F' && sb[2] == 'D')){
        cout << 11;
	}
	else if((sa[2] == 'A' && sb[2] == 'C') || (sa[2] == 'C' && sb[2] == 'A')){
		cout << 10;
	}else{
		cout << 0 << 0;
	}
    return 0;
}
