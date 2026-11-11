#include <bits/stdc++.h>
using namespace std;
int main (){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	string a,b,c,d;
	cin >> a >> b >> c >> d;
	
	bool f[4]={false , false , false , false};
	
	if(a == c){
		f[0] = true;
		if(b[0] == d[0] && b[1] == d[1]){
			f[1] = true;
			if( (b[2]=='A' || b[2]=='B' || b[2]=='C') && (d[2]=='A' || d[2]=='B' || d[2]=='C') ){
				
				f[2] = true;
				
				if(b[2] > d[2]){
					if(b[2] - d[2] == 1) f[3] = true;
				}
				else if(b[2] < d[2]){
					if(d[2] - b[2] == 1) f[3] = true;
				}
			}
			else if((b[2]=='D' || b[2]=='F') && (d[2]=='D' || d[2]=='F')){
				f[2] = true;
				f[3] = true;
			}
		}
	}
	
	for(int i=0;i<4;i++){
		if(f[i]) cout << 1;
		else cout << 0;
	}
	
	return 0;
} 
