#include<bits/stdc++.h>
using namespace std;
int q,w;
string a,b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> q >> a >> w >> b;
    for(int i=1;i<=4;i++){
    	if(q==w){
    	cout << "1";
    	if(a[2]==b[2]){
    		cout << " 1";
    		if(a[3]>='A'&&a[3]<='C'&&b[3]>='A'&&b[3]<='C'||a[3]=='D'||a[3]=='F'&&b[3]=='D'||b[3]=='F'){
    			cout << "1";
    			if(a[3]+1==b[3]||a[3]-1==b[3]){
    				cout << "1";
				}
				else{
					cout << "0";
				}
			}
			else{
				cout << "00";
			}
		}
		else{
			cout << "000";
		}
	}
	else{
		cout << "0000";
	}
	break;
	}
	return 0;
}