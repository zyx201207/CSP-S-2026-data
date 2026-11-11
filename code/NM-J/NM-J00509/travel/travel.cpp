#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	int cnt1=0;
	int cnt2=0;
	cnt1=int(s1[0]-'0')*10+int(s1[1]-'0');
	cnt2=int(s2[0]-'0')*10+int(s2[1]-'0');
	char a,b;
	a=s1[2];
	b=s2[2];
	if(c1==c2){
		cout<<1;
	}
	else{
		cout<<"0000";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if(cnt1==cnt2){
		cout<<1;
	}
	else{
		cout<<"000";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if((a>='A'&&a<='C'&&b>='A'&&b<='C')||(a>='D'&&a<='E'&&b>='D'&&b<='E')){
		cout<<1;
	}
	else{
		cout<<"00";
		fclose(stdin);
		fclose(stdout);
		return 0;
	}
	if((a>='D'&&a<='E'&&b>='D'&&b<='E')||(a>='A'&&a<='C'&&b>='A'&&b<='C'&&int(abs(int(a)-int(b)))==1)){
		cout<<1; 
	}
	else{
		cout<<0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
