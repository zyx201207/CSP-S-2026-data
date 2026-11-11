#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> a >> b >> c >> d;
	if (a == c){
	    cout << "1";
	    int n = b.length(),m = d.length();
	    if (n != m) {cout << "000"; return 0;}
	    for (int i = 0;i < n-1;i++){
	        if (b[i] != d[i]) {cout << "000"; return 0;}
	    }
        cout << "1";
        if ((b[n-1] >= 'A' && b[n-1] <= 'C' && d[n-1] >= 'A' && d[n-1]<= 'C') || (b[n-1] >= 'D' && b[n-1] <= 'F' && d[n-1] >= 'D' && d[n-1]<= 'F')){
            cout << "1";
            if (b[n-1] == 'B' || d[n-1] == 'B' || b[n-1] == 'D' || b[n-1] == 'F') cout << "1";
            else cout << "0";
        }
        else cout << "00";
	}
	else cout << "0000";
    return 0;
}
