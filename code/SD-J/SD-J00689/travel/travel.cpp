#include<bits/stdc++.h>
using namespace std;
int a,b,l,r,bbb1,bbb2,bbb3,bbb4;
string s1,s2;
bool pooop(string o,string h){
	if(o[2]<='C'&&h[2]<='C'){
		return 1;
	}
	if(o[2]>'C'&&h[2]>'C'){
		return 1;
	}
	if(o[2]<='C'&&h[2]>'C'){
		return 0;
	}
	if(o[2]>'C'&&h[2]<='C'){
		return 1;
	}
	return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s1>>b>>s2;
	if(a==b){
		bbb1=1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			bbb2=1;
			if(pooop(s1,s2)){
				bbb3=1;
				if(s1[2]+1==s2[2]||s2[2]+1==s1[2]){
					bbb4=1;
				}
			}
		}
	}
	cout<<bbb1<<bbb2<<bbb3<<bbb4;
	return 0;
}
