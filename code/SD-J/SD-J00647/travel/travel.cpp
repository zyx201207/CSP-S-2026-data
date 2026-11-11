#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string s_1,s_2,s_3,s_4;
	cin>>s_1>>s_2>>s_3>>s_4;
	bool flag=0;
	if(s_1==s_3)cout<<1;
	else{
		cout<<0;
		flag=1;
	} 
	if(s_2[0]==s_4[0]&&s_2[1]==s_4[1]&&!flag){
		cout<<1;
		if(s_2[2]-'A'<=3&&s_4[2]-'A'<=3)cout<<1;
		else if(s_2[2]-'A'>3&&s_4[2]-'A'>3)cout<<1;
		else cout<<0;
	}else cout<<"00";
	int a=s_2[0]-'0'*10+s_2[1]-'0';
	int b=s_4[0]-'0'*10+s_4[1]-'0';
	int c=s_2[2]-'A';
	int d=s_4[2]-'A';
	if(abs(a-b)==0&&abs(c-d)==1&&!flag){
		if(c==2&&d==3||c==3&&d==2)cout<<0;
		else cout<<1;
	}else cout<<0;
}
