#include "bits/stdc++.h"
using namespace std;	
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string h1,c1,h2,c2;
	cin >> h1>>c1>>h2>>c2;
	if(h1!=h2){
		cout << "0000";
		return 0;
	}
	string som="0000";
	som[0]='1';
	for(int i = 0;i<=1;i++){
		if(c1[i]==c2[i]){
			for(int j = 0;j<=1;j++){
				som[j]='1';	
			}
		}
		else{
			cout << "1000";
			return 0;
		}
	}
	if((c1[2]=='A'||c1[2]=='B'||c1[2]=='C')&&(c2[2]=='D'||c2[2]=='F')){
		som[2]='0';
		som[3]='0';
	}
	else{
			if((c2[2]=='A'||c2[2]=='B'||c2[2]=='C')&&(c1[2]=='D'||c1[2]=='F')){
		som[2]='0';
		som[3]='0';
	}
	else{
		som[2]='1';
		if(char(c1[2]+1)==c2[2]||char(c1[2]-1)==c2[2]||char(min(c1[2],c2[2])+2)==max(c1[2],c2[2])||char(max(c1[2],c2[2])-2)==min(c1[2],c2[2])){		
		som[3]='1';
	}
	else{
		som[2]='1';
		som[3]='0';
	}
}
}
    for(int i = 0;i <= 3;i++){
    	cout << som[i];
	}
	return 0;
	
}
