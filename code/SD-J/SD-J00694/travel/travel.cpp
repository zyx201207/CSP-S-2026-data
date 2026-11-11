#include<bits/stdc++.h>

using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string src,srp,sxc,sxp;
	cin >> src >> srp >> sxc >> sxp;
	char a[4] = {srp[0],srp[1]};
	char b[4] = {sxp[0],sxp[1]};
	string sr = a,sx = b;
	int ccr = srp[2]-65,ccx = sxp[2]-65;
	if(src == sxc){
		cout << "1";
		if(sr == sx){
			cout << "1";
			if(sr == sx && ((ccr == 0 || ccr == 1 || ccr == 2) && (ccx == 0 || ccx == 1 || ccx == 2) || ((ccr == 3 || ccr == 4) && (ccx == 3 || ccx == 4)))){
				cout << "1";
				if(fabs(ccr-ccx) == 1 && ((ccr != 2 && ccx != 3) && (ccx != 2 && ccr != 3))){
					cout << "1" << endl;
				}
				else{
					cout << "0" << endl;
				}
			}
			else{
				cout << "00" << endl;
			}
		}
		else{
			cout << "000" << endl;
		}
	}
	else{
		cout << "0000" << endl;
	}
	
	
	
	fclose(stdin);
	fclose(stdout); 
	return 0;
} 
