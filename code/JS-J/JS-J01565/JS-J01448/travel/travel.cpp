#include<bits/stdc++.h>
using namespace std;
long long n,m;
long long a[200000];
string s,s2,s3,s4;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>> s >> s2 >> s3 >> s4;
    if(s==s3){
        cout<< "1";
        if(s2[0]==s4[0] && s2[1]==s4[1]){
            cout<< "1";
            if(('A'<=s2[2] && s2[2]<='C' && 'A'<=s4[2] && s4[2]<='C') || ('D'<=s2[2] && s2[2]<='F' && 'D'<=s4[2] && s4[2]<='F')){
				cout<< "1";
				if(s2[2]=='A'){
					if(s4[2]=='B'){
						cout<< "1" <<endl;
					}
					else{
						cout<< "0" <<endl;
					}
				}
				else if(s2[2]=='B'){
					if(s4[2]=='A' || s4[2]=='C'){
						cout<< "1" <<endl;
					}
					else{
						cout<< "0" <<endl;
					}
				}
				else if(s2[2]=='C'){
					if(s4[2]=='B'){
						cout<< "1" <<endl;
					}
					else{
						cout<< "0" <<endl;
					}
				}
				else if(s2[2]=='D'){
					if(s4[2]=='F'){
						cout<< "1" <<endl;
					}
					else{
						cout<< "0" <<endl;
					}
				}
				else{
					if(s4[2]=='D'){
						cout<< "1" <<endl;
					}
					else{
						cout<< "0" <<endl;
					}
				}
			}
			else{
				cout<< "00" <<endl;
			}
		}
		else{
			cout<< "000" <<endl;
		}
    }
    else{
        cout<< "0000" <<endl;
    }
    return 0;
}
