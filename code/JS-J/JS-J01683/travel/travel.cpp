#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a1,a2;
	string s1,s2;
	cin>>a1>>s1>>a2>>s2;//cin
	
	short ans=1;
	ans*=int(a1==a2);
	cout<<int(a1==a2);//1
	ans*=int(s1.substr(0,2)==s2.substr(0,2));
	cout<<int(ans&&(s1.substr(0,2)==s2.substr(0,2)));//2
	ans*=int(((s1[2]>='D')&&(s2[2]>='D'))||((s1[2]<='C')&&(s2[2]<='C')));
	cout<<int(ans&&(((s1[2]>='D')&&(s2[2]>='D'))||((s1[2]<='C')&&(s2[2]<='C'))));//3
	if(!ans)cout<<0;
	else if(abs(s1[2]-s2[2])==1)cout<<1<<endl;
	else cout<<0;
	return 0;
}
