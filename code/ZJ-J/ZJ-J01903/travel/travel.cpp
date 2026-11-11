#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    string x,y,a,b;
    bool flag = true;
    cin >> x >> a >> y >> b;
    if( x == y)
		cout << '1';
    else{
        flag = false;
        cout << '0';
    }
    if(flag && a[0] == b[0] && a[1] == b[1])
		cout << '1';
    else{
        flag = false;
        cout << '0';
    }
    if(flag && ((a[2]<= 'C' && b[2] <= 'C')||(a[2]>= 'D'&& b[2] >= 'D')))
		cout << '1';
    else{
        flag = false;
        cout << '0';
    }
    if(flag && (abs(int(a[2]-b[2])) == 1))
		cout << '1';
    else{
        cout << '0';
    }
    return 0;
}

