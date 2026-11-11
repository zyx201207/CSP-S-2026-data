#include<bits/stdc++.h>
using namespace std;
string a,b;
char c,d;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=1;i++){
		a=s1[i]+a;
		b=s2[i]+b;
	}
	c=s1[2],d=s2[2];
	if(c1==c2)
		cout<<'1';
	else{
		cout<<"0000";
		return 0;
	}
	if(c1==c2&&a==b){
		cout<<'1';
	}else{
		cout<<"000";
		return 0;
	}
	if(c1==c2&&a==b&&(c=='A'||c=='B'||c=='C')&&(d=='A'||d=='B'||d=='C'))
		cout<<'1';
	else{
		cout<<"00";
		return 0;
	}
	if(c1==c2&&a==b&&(((c=='A'||c=='B'||c=='C')&&(d=='A'||d=='B'||d=='C'))||((c=='D'||c=='F')&&(d=='D'||d=='F')))&&(c=='A'&&d=='B')||(c=='B'&&d=='A')||(c=='C'&&d=='B')||(c=='B'&&d=='C')||(c=='D'&&d=='F')||(c=='F'&&d=='D'))
		cout<<'1';
	else{
		cout<<"0";
		return 0;
	}
	return 0;
}
/*

02 01C 02 01D
1100

02 02B 02 01A
1000

02 01C 02 01A
1110
*/
