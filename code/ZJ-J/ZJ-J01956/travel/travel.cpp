#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	map<char,int>x;
	x['A']=1,x['B']=2,x['C']=3,x['D']=6,x['F']=7;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else cout<<0;//
	
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1]){
		cout<<1;
	}
	else cout<<0;
	
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && abs(x[s1[2]]-x[s2[2]])<=2)
		cout<<1;
	else cout<<0;
	
	if(c1==c2 && s1[0]==s2[0] && s1[1]==s2[1] && abs(x[s1[2]]-x[s2[2]])==1)
		cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
