#include<bits/stdc++.h>
using namespace std;
bool check(string a,string b){
	char ca=a[a.size()-1];
	char cb=b[b.size()-1];
	if(a!=b)return 0;
	else return 1;
}
bool check_pai(string a,string b){
	int an=0,bn=0;
	for(int i=0;i<a.size();i++)if(isdigit(a[i]))an=an*10+(a[i]-'0');
	for(int i=0;i<b.size();i++)if(isdigit(b[i]))bn=bn*10+(b[i]-'0');
	if(an==bn)return 1;
	else return 0;
}
bool check_ce(string a,string b){
	char ac,bc;
	for(int i=0;i<a.size();i++)if(!isdigit(a[i]))ac=a[i];
	for(int i=0;i<b.size();i++)if(!isdigit(b[i]))bc=b[i];
	if(ac>='A'&&ac<='C'&&bc>='A'&&bc<='C')return 1;
	else if(ac>='D'&&ac<='F'&&bc>='D'&&bc<='F')return 1;
	else return 0;
}
bool check_lin(string a,string b){
	char ac,bc;
	for(int i=0;i<a.size();i++)if(!isdigit(a[i]))ac=a[i];
	for(int i=0;i<b.size();i++)if(!isdigit(b[i]))bc=b[i];
	if(ac=='F'||ac=='D')return 1;
	else if(bc==ac+1||bc==ac-1)return 1;
	else return 0; 
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(!check(c1,c2))cout<<"0000";
	else{
		cout<<1;
		if(!check_pai(s1,s2))cout<<"000";
		else{
			cout<<1;
			if(!check_ce(s1,s2))cout<<"00";
			else{
				cout<<1;
				if(!check_lin(s1,s2))cout<<0;
				else cout<<1;
			}
		}
	}
	return 0;
}
