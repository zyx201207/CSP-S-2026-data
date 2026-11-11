#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
char f='0',w='0',v='0',t='0';	
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c){
		f='1';
		if(b[0]==d[0]&&b[1]==d[1]){
			w='1';
			if(b[2]=='A'||b[2]=='B'||b[2]=='C'){
				if(d[2]=='A'||d[2]=='B'||d[2]=='C'){
				v='1';
				}
			}else{
				if(d[2]=='D'||d[2]=='F'){
				v='1';
				t='1';
				}
			}
		}
	}
	if(f=='1'&&w=='1'&&v=='1'){
		if(b[2]=='A'&&d[2]=='B'){
			t='1';
		}else if(b[2]=='B'&&d[2]=='A'){
			t='1';
		}else if(b[2]=='B'&&d[2]=='C'){
			t='1';
		}else if(b[2]=='C'&&d[2]=='B'){
			t='1';
		}
	}
	cout<<f<<w<<v<<t;
	return 0;		
}																																				