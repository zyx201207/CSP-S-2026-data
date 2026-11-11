#include<bits/stdc++.h>
using namespace std;
string s1,s2;
int c1,c2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	string s;
	if(c1==c2){
		s+='1';
	}else{
		s+='0';
	}
	string a,b;
	a+=s1[0]+s1[1];
	b+=s2[0]+s2[1];
	if(a==b and c1==c2){
		s+='1';
	}else{
		s+='0';
	}
	if(c1==c2 and a==b and ((s1[2]>='A' and s1[2]<='C' and s2[2]>='A' and s2[2]<='C')or(s1[3]>='D' and s1[3]<='F' and s2[3]>='D' and s2[3]<='F'))){
		s+='1';	
	}else{
		s+='0';
	}
	if(c1==c2 and a==b and ((s1[2]>='A' and s1[2]<='C' and s2[2]>='A' and s2[2]<='C')or(s1[3]>='D' and s1[3]<='F' and s2[3]>='D' and s2[3]<='F'))){
		if(s1[2]+1==s2[2] or s2[2]+1==s1[2]){
			s+='1';
		}else{
			s+='0';
		}
	}else{
		s+='0';
	}
	cout<<s;
	return 0;
}
