#include<bits/stdc++.h>
using namespace std;

int main()
{
	//freopen("travel","r",stdin);
	//freopen("travel","w",stdout);
	
	char c1,s1,c2,s2;
	printf("%d %d %d %d",&c1,&s1,&c2,&s2);
	if(c1==c2){
		cout<<"1"<<endl;
	}
	else{
		cout<<"0000"<<endl;
		break;
	}
	if(s1[1]==s2[1]){
		cout<<"1"<<endl;
	}
	else{
		cout<<"0000"<<endl;
		break;
	}
	if(s1[0]==s2[0]){
		cout<<"1"<<endl;
	}
	else{
		cout<<"0000"<<endl;
		break;
	}
	if(s1[2]=="D"&&s1[2]=="F")
	{
		cout<<"1"<<endl;
	}
	else{
		cout<<"0000"<<endl;
	}
	
	fcolse(stdin);
	fcolse(stdout);
	return 0;
}