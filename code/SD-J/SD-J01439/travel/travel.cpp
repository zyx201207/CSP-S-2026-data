#include<bits/stdc++.h>
using namespace std;

string s1,s2,train_number1,train_number2;

int main(){
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	int f=0;
	cin>>train_number1>>s1>>train_number2>>s2;
	if(train_number1==train_number2) cout<<1;
	else cout<<0,f=1;
	int s1_number=(s1[0]-'0')*10+s1[1]-'0';
	int s2_number=(s2[0]-'0')*10+s2[1]-'0';
	if(s1_number==s2_number&&!f) cout<<1;
	else cout<<0,f=1;
	if(s1[2]>='D'&&s2[2]>='D'||s1[2]<='D'&&s2[2]<='D'&&!f) cout<<1;
	else cout<<0,f=1;
	if(abs(s1[2]-s2[2])==1&&!f) cout<<1;
	else cout<<0;
	
	return 0;
}
