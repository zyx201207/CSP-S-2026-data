#include <bits/stdc++.h>
using namespace std;

bool f[10];

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string c1,c2,s1,s2;
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1==c2){
		f[1] = 1;
		if((s1[0]==s2[0])&&(s1[1]==s2[1])){
			f[2] = 1;
			if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>'C'&&s2[2]>'C')){
				f[3] = 1;
				if((s1[2]-s2[2]==1)||(s2[2]-s1[2]==1)){
					f[4] = 1;
				}
			}
		}
	}
	
	for(int i=1;i<=4;i++) cout << f[i];
	
	fclose(stdin);
	fclose(stdout);
	
	return 0;

}
