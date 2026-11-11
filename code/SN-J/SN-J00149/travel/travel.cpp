#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel5.in","r",stdin);
	freopen("travel5.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(int(c1[0])==int(c2[0])&&int(c1[1])==int(c2[1])){
		cout<<1;
	}else{
		cout<<0<<0<<0<<0;
		return 0;
	}
	if(int(s1[0])==int(s2[0])&&int(s1[1])==int(s2[1])){
		cout<<1;
	}else{
		cout<<0<<0<<0;
		return 0;
	}
	if((int(s1[2])>=65&&int(s1[2])<=67&&int(s2[2])>=65&&int(s2[2])<=67)){
		cout<<1;
		if(abs(int(s1[2])-int(s2[2]))==1){
			cout<<1;
		}else{
			cout<<0;
		}
	}else if((int(s1[2])>=68&&int(s1[2])<=69&&int(s2[2])>=68&&int(s2[2])<=69)){
		cout<<1<<1;
	}else{
		cout<<0<<0;
	}
	return 0;
} 
