#include<iostream> 
#include<cstring>
using namespace std;
string c1,s1,c2,s2;
int sum=0,cnt=0;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdin);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		sum++;
	}
	else{
		cout<<0;
	}

    if(s1!=s2&&(s1[0]==s2[0]&&s1[1]==s2[1])){
		cout<<1;
		sum++;
	}
	else{
		cout<<0;
	}
	if(sum==2&&(s1[2]=='A'||s1[2]=='B'||s1[2]=='C')&&(s2[2]=='A'||s2[2]=='B'||s2[2]=='C')){
		cout<<1;
	}
	else if(sum==2&&(s1[2]=='D'||s1[2]=='F')&&(s2[2]=='D'||s2[2]=='F')){
		cout<<1;
	}
	else{
		cout<<0;
	}
	if((s1[2]=='D'&&s2[2]=='F')||(s1[2]=='A'&&s2[2]=='B')||(s1[2]=='B'&&s2[2]=='C')){
		cout<<1;
		sum++;
	}
	else{
		cout<<0;
	}
	return 0;
}
