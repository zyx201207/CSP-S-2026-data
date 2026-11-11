#include<bits/stdc++.h>
using namespace std;

string s,c,ss,cc;
bool flag=0;

bool f(string a,string b){
	if('A'<=a[2]&&a[2]<='C'){
		if('A'<=b[2]&&b[2]<='C'){
			return 1;
		}else{
			return 0;
		}
	}else{
		if('A'<=b[2]&&b[2]<='C'){
			return 0;
		}else{
			return 1;
		}
	}
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	if(s[0]==ss[0]&&s[1]==ss[1]){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if(f(s,ss)){
		cout<<1;
	}else{
		cout<<"00";
		return 0;
	}
	if((int)s[2]+1==(int)ss[2]||(int)s[2]-1==(int)ss[2]){
		cout<<1;
	}else{
		cout<<0;
	}
	return 0;
}
