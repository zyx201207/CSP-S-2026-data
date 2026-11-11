#include<bits/stdc++.h>
#define CLOSE ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
#define endl "\n"
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	CLOSE
	int a1=0,a2=0,a3=0,a4=0;
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		a1=1;
		string s3=s1.substr(0,2);
		string s4=s2.substr(0,2);
		if(s3==s4){
			a2=1;
			string s5=s1.substr(2,1);
			string s6=s2.substr(2,1);
			if(s5>="A"&&s5<="C" && s6>="A" && s6<="C"){
				a3=1;
			}
			else if((s5=="D"&&s6=="F") || (s6=="D" && s5=="F")){
				a3=1;
				a4=1;
			}
			if(!a4 && a1 && a2 && a3 && (s5[0]+1==s6[0] || s5[0]-1==s6[0]) && (s6[0]+1==s5[0] || s6[0]-1==s5[0])){
				a4=1;
			}
		}
    }
    cout<<a1<<a2<<a3<<a4;
	return 0;
} 
