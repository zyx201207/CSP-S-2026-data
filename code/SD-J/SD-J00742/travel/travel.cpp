#include<bits/stdc++.h>
using namespace std;
string c,c1,s,s1;
int n,m;
bool w;
int main(){
	freopen("ravel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>c1>>s>>s1; 
	n=(c1[0]-'0')*10+c1[1]-'0';
	m=(s1[0]-'0')*10+s1[1]-'0';
	if(c==s){
		cout<<1;
		w=1;
	}else{
		cout<<0;
	}
	if(n==m&&w){
		cout<<1;
	}else{
		cout<<0;
		w=0;
	}
	if((c1[2]<='C'&&s1[2]<='C'||c1[2]>'C'&&c1[2]>'C')&&w){
		cout<<1;
	}else{
		cout<<0;
		w=0;
	}
	if((c1[2]+1==s1[2]||c1[2]-1==s[2])&&w){
		cout<<1;
	}else{
		cout<<0;
	}
	
	return 0;
}
