#include<bits/stdc++.h>
using namespace std;
string cx,id,cx2,id2;
int a[10] = {0,1,1,1,2,2};
int check(char c){
	if(c == 'A'){
		return 1;
	}
	if(c == 'B'){
		return 2;
	}
	if(c == 'C'){
		return 3;
	}
	if(c == 'D'){
		return 4;
	}
	if(c == 'F'){
		return 5;
	}
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin >> cx >> id >> cx2 >> id2;
	if(cx == cx2){
		cout << 1;
		if(id[0] == id2[0] && id[1] == id2[1]){
			cout << 1;
			int p = check(id[2]);
			int p2 = check(id2[2]);
			if(a[p] == a[p2]){
				cout << 1;
				if(abs(p2-p) == 1){
					cout << 1;
				}else{
					cout << 0;
				}
			}else{
				cout << "00";
			}
		}else{
			cout << "000";
		}
	}else{
		cout << "0000";
	}
	
	fclose(stdin);
	fclose(stdout);
	return 0;
}
