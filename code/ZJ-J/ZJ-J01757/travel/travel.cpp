#include<bits/stdc++.h>
using namespace std;
int main(){
	ifstream f_in("travel.in");
	ofstream f_out("travel.out");
	char c1[2],c2[2],s1[3],s2[3];
	f_in>>c1[0]>>c1[1]>>s1[0]>>s1[1]>>s1[2]>>c2[0]>>c2[1]>>s2[0]>>s2[1]>>s2[2];
	if((c1[0]*10+c1[1])==(c2[0]*10+c2[1])){
		f_out<<"1";
		if((s1[0]*10+s1[1])==(s2[0]*10+s2[1])){
			f_out<<"1";
			if(('A'==s1[2]||'B'==s1[2]||'C'==s1[2])&&('A'==s2[2]||'B'==s2[2]||'C'==s2[2])){
				f_out<<"1";
				if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
					f_out<<"1";
				}else{
					f_out<<"0";
				}
			}else if(('D'==s1[2]||'E'==s1[2])&&('D'==s2[2]||'E'==s2[2])){
				f_out<<"1";
				if(s1[2]-s2[2]==1||s1[2]-s2[2]==-1){
					f_out<<"1";
				}else{
					f_out<<"0";
				}
			}else{
				f_out<<"00";
			}
		}else{
			f_out<<"000";
		}
	}else{
		f_out<<"0000";
	}
	return 0;
}
