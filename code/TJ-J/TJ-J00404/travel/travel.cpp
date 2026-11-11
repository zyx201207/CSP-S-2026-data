#include<bits/stdc++.h>
using namespace std;
int a,b;
string s,t;
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>s>>b>>t;
    int cnt=(s[0]-'0')*10+s[1]-'0';
    int ans=(t[0]-'0')*10+t[1]-'0';
	if(a==b){
		cout << 1;
		if(cnt==ans){
   		 	cout << 1;
 	 	  	if(s[2]>='A'&&s[2]<='C'&&t[2]>='A'&&t[2]<='C'){
 	 	  			cout<<1;
 	 	  			if(abs(s[2]-t[2])==1&&(s[2]!='C'&&t[2]!='D')&&(s[2]!='D'&&t[2]!='C'))cout <<1;
   					else cout << 0;
				}
  		  	else if(s[2]>='D'&&s[2]<='E'&&t[2]>='D'&&t[2]<='E'){
  		  			cout << 1;
					if(abs(s[2]-t[2])==1&&(s[2]!='C'&&t[2]!='D')&&(s[2]!='D'&&t[2]!='C'))cout <<1;
   					else cout << 0;
				}
  		  	else cout << 0 << 0;
		}
		else cout << 0 << 0 << 0;
	}
    else cout << 0 << 0 << 0 << 0;
    return 0;
    }
