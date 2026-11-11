#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	int n,m;
	int flaga;
	string one, second;
	cin >> n >> one >> m >> second;
	if (n == m){
		cout << '1';
			if (one[0] == second[0] && one[1] == second[1]){
				cout << '1';
				if (one[2] == 'A' || one[2] == 'B' || one[2] == 'C' && second[2] == 'A' || second[2] == 'B' || second[2] == 'C'){
						cout << '1';
						if (one[2] == 'A' && second[2] == 'B' || second[2] == 'A' && one[2] == 'B'){
							cout << '1';
						}
						else if (one[2] == 'B' && second[2] == 'C' || one[2] == 'C' && one[2] == 'B'){
							cout << '1';
						}
						else if (one[2] == 'E' && second[2] == 'F' || one[2] == 'F' && second[2] == 'E'){
							cout << '1';
						}
						else {
							cout << '0';
						}
					}
				
				else if (one[2] == 'E' || one[2] == 'F' && second[2] == 'E' || second[2] == 'F'){
						if (one[2] == 'E' && second[2] == 'F' || second[2] == 'F' && one[2] == 'E'){
							cout << '1';
						}
						else {
							cout << '0';
						}				
				}
				else {
					cout << '0' << '0';
				}
			}
			else{
				cout << '0' << '0' << '0';
			}  
	}	
	else {
		cout << '0' << '0' << '0' << '0';
	}
	
	return 0;
	
	
	
	fclose(stdin);
	fclose(stdout);
}
