#include <bits/stdc++.h>
using namespace std;
bool check1(string a,string b){
	return a==b;
}
bool check2(string a,string b,string x,string y){
	string s,d;
	for(int i=0;i<a.size()-1;i++) s+=a[i];
	for(int i=0;i<b.size()-1;i++) d+=b[i];
	if(check1(x,y)){
		if(s==d) return true;
		else return false;
	} 
	return false;
}
bool check3(string a,string b,string x,string y){
	char s=a[2];
	char d=b[2];
	if(check2(a,b,x,y)){
		if(s>='A'&&s<='C'){
			if(d>='A'&&d<='C'){
				return true;
			}
			else{
				return false;
			}
		}
		else{
			if(d>='D'&&d<='F'){
				return true;
			}
			return false;
		}
	}
	return false;
}
bool check4(string a,string b,string x,string y){
	char s=a[2];
	char d=b[2];
	if(check3(a,b,x,y)){
		if(abs((int)s-(int)d)==1){
			return true;
		}
	}
	return false;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	cout<<check1(c1,c2)<<check2(s1,s2,c1,c2)<<check3(s1,s2,c1,c2)<<check4(s1,s2,c1,c2);
	return 0;
}
