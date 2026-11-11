#include<bits/stdc++.h>
using namespace std;
int a,b;
string m,n;
bool check(string s1,string s2){
	char j=s1[2],k=s2[2];
	if (j<='C'){
		if (k<='C')
			return 1;
		else
			return 0;
	}
	else{
		if (k>='D')
			return 1;
		else
			return 0;
	}
}
bool is_cd(char x,char y){
	if (x=='C' && y=='D')
		return 1;
	if (x=='D' && y=='C')
		return 1;
	return 0;
} 
int main(){
	//I love NOI,能给个满分吗,第一题应该不难吧 
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>m>>b>>n;
	if (a==b)
		cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	int r=int((m[0]-'0')*10+(m[1]-'0')),
	x=int((n[0]-'0')*10+(n[1]-'0'));
	if (r==x)
		cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	if (check(m,n))
		cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if (abs(int(m[2]-n[2]))==1 && !is_cd(m[2],n[2]))
		cout<<1;
	else
		cout<<0;
	return 0;
}
