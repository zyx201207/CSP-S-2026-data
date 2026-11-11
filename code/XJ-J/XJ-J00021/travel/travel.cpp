#include<bits/stdc++.h>
using namespace std;
string s;
char c['0,1'],d['0,1,2'],e['0,1'],f['0,1,2'];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>d>>e>>f;
	if(c[0]==e[0]&&c[1]==e[1]){
		s+='1';
	}else{
		s+='0';
	}
	if(d[0]==f[0]&&d[1]==f[1]){
		s+='1';
	}else{
		s+='0';
	}
	if(d[2]==f[2]){
		s+='1';
		s+='1';
	}else{
		s+='0';
		s+='0';
	}
	cout<<s;
	return 0;
} 
