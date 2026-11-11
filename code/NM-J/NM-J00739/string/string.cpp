#include <iostream>
#include <string>
#include <cmath>     
using namespace std;
string p(int a,string b){
	string c = "";
	for(int i = 0;i<a;i++){
		c = c+b;
	}
	return c;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int a;
	string d="";
	cin>>a;
	int ans =0;
	for(int i = 0;i<a;i++){
		int b;string c;
		cin>>b>>c;
		d = d + p(b,c);
	}
	for(int i = 0;i<floor(d.length()/2);i++){
		if(d[i] != d[d.length() -1 -i]){
			ans++;
		}
	}
	cout<<ans;
	return 0;
}
