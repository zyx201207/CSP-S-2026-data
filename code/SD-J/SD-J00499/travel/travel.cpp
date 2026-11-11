#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
map<char,int> m;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	m['A']=1;
	m['B']=1;
	m['C']=1;
	m['D']=2;
	m['F']=2;
	cin>>a>>b>>c>>d;
	if(a[0]==c[0]&&a[1]==c[1]){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(a[0]==c[0]&&a[1]==c[1]&&b[0]==d[0]&&b[1]==d[1]){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(a[0]==c[0]&&a[1]==c[1]&&b[0]==d[0]&&b[1]==d[1]&&m[b[2]]==m[d[2]]){
		cout<<'1';
	}else{
		cout<<'0';
	}
	if(a[0]==c[0]&&a[1]==c[1]&&b[0]==d[0]&&b[1]==d[1]&&m[b[2]]==m[d[2]]&&(b[2]==char(d[2]+1)||d[2]==char(b[2]+1))){
		cout<<'1';
	}else{
		cout<<'0';
	}
	return 0;
}
 
