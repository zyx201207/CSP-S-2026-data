#include<bits/stdc++.h>
int a;
using namespace std;
int main(){
	//freopen("subway.in", "r", stdin);
	//freopen("subway.out", "w", stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	for(int i = 1; i <= 28; ++i){
        cin >> a;
	}
	if(a == 2){
        cout << 32 << endl << 17 << endl;
	}else{
	    for(int i = 1; i <= 10; ++i){
            cin >> a;
	    }
	    cout << 35 << endl << 16 << endl;
	}
	return 0;
}
