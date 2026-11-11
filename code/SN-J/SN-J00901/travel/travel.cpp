#include<iostream>
#include<string>
using namespace std;
int main(){
	preopen("travel","r",stdin);
	preopen("travel","w",stdout);
	int c1;
	string s1;
	int c2;
	string s2;
	cin>>c1>>c2>>s1>>s2;
	int a=0,b=0,c,d=0;
	if(c1==c2){
		a=1;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1]){
		b=1;
	}
	if(s1[2]--s2[2]==1){
		c=1;
	}
	else if(s1[2]--s2[2]==2){
		c=1;
	}
	else if(s2[2]--s1[2]==1){
		c=1;
	}
	}else{
		c=0;
	}
	if(s1[2]==D&&s2[2]==F){
		d=1;
	}
	return 0;
}
