#include<bits/stdc++.h>
#define ll long long 
using namespace std;
ll c,cc;//车厢号 
string s,ss;//座位号 
int check(char a){
	if(a>='A'&&a<='C'){
		return 1;
	}else{
		return 0;
	}
} 
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c>>s>>cc>>ss;
	if(c==cc){//同一车厢 
		cout<<1;
		if(s[1]==ss[1]&&s[0]==ss[0]){//同一排 
			cout<<1;
			if(check(s[2])==check(ss[2])){//同一侧 
				cout<<1;
				if((char(s[2]+1)==ss[2]||char(s[2]-1)==ss[2])&&((s[2]!='C'&&ss[2]!='D')||(s[2]!='D'&&ss[2]!='C'))){
					cout<<1;
				}else{
					cout<<0;
				}
			}else{
				cout<<"00";
			} 
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
