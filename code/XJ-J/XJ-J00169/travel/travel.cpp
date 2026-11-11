#include<bits/stdc++.h>
using namespace std;
char t1,t2;
int c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>c1>>s1>>t1>>c2>>s2>>t2;
	if(c1!=c2)
		cout<<"0000";
	else if(s1!=s2)
		cout<<"1000";
	else{
		if((t1>='A'&&t1<='C'&&t2>='A'&&t2<='C')||(t1=='D'&&t2=='F')||(t1=='F'&&t2=='D')){
			if((int)t1+1==(int)t2||(int)t2+1==(int)t1||(t1=='D'&&t2=='F')||(t1=='F'&&t2=='D'))
				cout<<"1111";
			else
				cout<<"1110";
		}else
			cout<<"1100";
	}
	return 0;
}
