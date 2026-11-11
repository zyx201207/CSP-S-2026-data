#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	cin>>a>>b>>c>>d;
	int c1,c2,s1,s2,e=b[2]-'A'+1,f=d[2]-'A'+1;
	c1=(a[0]-'0')*10+(a[1]-'0'),c2=(c[0]-'0')*10+(c[1]-'0');
	s1=(b[0]-'0')*10+(b[1]-'0'),s2=(d[0]-'0')*10+(d[1]-'0');
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}
	else cout<<"1";
	if(s1!=s2){
		cout<<"000";
		return 0;
	}
	else cout<<"1";
	if((e==4||e==6)&&(f!=6||f!=4)||(f==4||f==6)&&(e!=6||e!=4)){
		cout<<"00";
		return 0;
	}
	else cout<<"1";
	if(e==4||f==4){
		cout<<"1";
		return 0;
	}
	if(abs(e-f)==1)cout<<"1";
	else cout<<"0";
	fclose(stdin);
	fclose(stdout);
	return 0;
} 
