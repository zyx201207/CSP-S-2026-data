#include<bits/stdc++.h>
using namespace std;
string a,b,c,d,bb,dd,m,n;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a==c)cout<<1;
	else {
		cout<<"0000";
		return 0;
	}
	bb=b[0];
	bb+=b[1];
	dd=d[0];
	dd+=d[1];
	n=b[2];
	m=d[2];
	if(bb==dd){
		cout<<"1";
	}else{
		cout<<"000";
	}
	if((m=="D"&&n=="F"||m=="F"&&n=="D")){
		cout<<11;
		return 0;
	}if((m=="F"&&n=="A"||m=="F"&&n=="B"||m=="F"&&n=="C")||(n=="F"&&m=="A"||n=="F"&&m=="B"||n=="F"&&m=="C")||(m=="D"&&n=="A"||m=="D"&&n=="B"||m=="D"&&n=="C")||(n=="D"&&m=="A"||n=="D"&&m=="B"||n=="D"&&m=="C")){
		cout<<"00";
		return 0;
	}if(m=="B"||n=="B"){
		cout<<"11";
		return 0;
	}if(m=="A"&&n=="C"){
		cout<<"10";
		return 0;
	}if(m=="C"&&n=="A"){
		cout<<"10";
		return 0;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
