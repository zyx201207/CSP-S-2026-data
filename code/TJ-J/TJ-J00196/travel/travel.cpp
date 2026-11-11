#include <bits/stdc++.h>
using namespace std;
bool r=false; 
char a[4]={'0','0','0','0'};
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string b,c,d,e;
	cin>>b>>d>>c>>e;
	if(b==c){
		a[0]='1';
	}
	if(d[0]==e[0]&&d[1]==e[1]){
		a[1]='1';
	}
	if(a[1]=='1'&&(d[2]<='C'&&e[2]<='C')){
		a[2]='1';
	}
	if(a[1]=='1'&&(d[2]=='D'||d[2]=='F')&&(e[2]=='D'||e[2]=='F')){
		a[2]='1';
		a[3]='1';
	} 
	if(d[2]+1==e[2]||d[2]-1==e[2]){
		a[3]='1';
	}
	for(int i=0;i<4;i++){
		cout<<a[i];
	}
	return 0;
}
