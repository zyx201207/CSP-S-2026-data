#include<bits/stdc++.h>

using namespace std;
int ans[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,c2;
	cin>>c1;
	getchar();
	char s1[5],s2[5];
	for(int i=0;i<3;i++)
		cin>>s1[i];
	getchar();
	cin>>c2;
	getchar();
	for(int i=0;i<3;i++)
		cin>>s2[i];
	if(c1==c2)
		ans[1]=1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])
		ans[2]=1;
	else{
		cout<<"1000";
		return 0;
	}
	if((s1[2]<='C'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]>='D'))
		ans[3]=1;
	else{
		cout<<"110";
		return 0;	
	}
	if(s1[2]+1==s2[2]||s2[2]+1==s1[2])
		cout<<"1111";
	else
		cout<<"1110";
	return 0;
} 
