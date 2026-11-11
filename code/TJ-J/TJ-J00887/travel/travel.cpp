#include <bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int cnt;
int main(){
	freopen("travel.in","r",stdin);
	freopen("trevel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
	    cout << 1;
	    cnt++;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
		    cout << 1;
		    cnt++;
		    if(int(s1[2]-s2[2])==2 || int(s1[2]-s2[2])==-2){
			    cout << 1;
			    cnt++;
		    	if((int(s1[2]-s2[2])==1 || int(s1[2]-s2[2])==-1) && (s1[2]!='C' && s2[2]!='D') && (s2[2]!='C' && s1[2]!='D')){
		    		cout << 1;
		    		cnt++;
				}
				else{
					cout << 0;
					cnt++;
				}
	        }
			else{
				cout << 0;
				cnt++;
			}
	    }
		else{
			cout << 0;
			cnt++;
		}
	} 
	else{
		cout << 0;
		cnt++;
	}
	for(int i=1;i<=4-cnt;i++){
		cout << 0;
	}
	return 0;
}
