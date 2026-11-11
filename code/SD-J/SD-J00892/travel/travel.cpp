#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int q[100];
bool f1=false,f2=false,f3=false;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	q['A']=1;q['B']=1;q['C']=1;q['D']=2;q['F']=2;
	if(c1==c2){
		cout<<'1';
		f1=true;
	}
	else cout<<'0';
	if(s1[0]==s2[0]&&s1[1]==s2[1]&&f1){
		cout<<'1';
		f2=true;
	}
	else cout<<'0';
	if(q[s1[2]]==q[s2[2]]&&f1&&f2){
		cout<<'1';
		f3=true;
	}
	else cout<<'0';
	if(f1&&f2&&f3) cout<<'1';
	else cout<<'0';
	return 0;
}
