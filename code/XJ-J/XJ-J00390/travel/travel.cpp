#include<bits/stdc++.h>
using namespace std;
string c1="",s1="",c2="",s2="";
int a=0,b=0,c=0,d=0;
char s[7] = {'A','B','C','D','F'};
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin >> c1 >> s1 >> c2 >> s2;
	if(c1 == c2)	a=1;
	
	if(s1[0]==s2[0]&&s1[1]==s2[1]) b=1;
	
	int ce1 = 0,ce2 = 0;
	if(s2[2] == 'A' ||s2[2] == 'B' || s2[2] == 'C'){
		ce2 =1;
	}else ce2 = 2;
	if(s1[2] == 'A' ||s1[2] == 'B' || s1[2] == 'C'){
		ce1 =1;
	}else ce1 = 2;
	if(ce1==ce2){
		c = 1;
	}
	
	if(c==1){
		for(int i = 0;i < 5;i++){
			if(i == 0){
				if((s[i] == s1[2] && s[i+1] == s2[2]) || (s[i] == s2[2] && s[i+1] == s1[2])){
					d = 1;
				}
			}if(i == 4){
				if((s[i] == s1[2] && s[i-1] == s2[2]) || (s[i] == s2[2] && s[i-1] == s1[2]) ){
					d = 1;
				}
			}else{
					if((s[i] == s1[2] && s[i-1] == s2[2]) || (s[i] == s2[2] && s[i-1] == s1[2]) ||(s[i] == s1[2] && s[i+1] == s2[2]) || (s[i] == s2[2] && s[i+1] == s1[2])){
					d = 1;
				}
				
			}
		}
	}
		
	cout << a << b << c << d;
	
	
	
	
	//8:54 ok
	
	return 0;
	

	
}