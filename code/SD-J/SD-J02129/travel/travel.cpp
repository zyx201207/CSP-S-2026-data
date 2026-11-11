#include<bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	char x1=s1[2],x2=s2[2];
	map<char,int> ump;
	ump['A']=ump['B']=ump['C']=0;
	ump['D']=ump['F']=1;
	int n1=(s1[0]-'0')*10+(s1[1]-'0'),n2=(s2[0]-'0')*10+(s2[1]-'0');
	if(c1!=c2) cout<<"0000";
	else if(n1!=n2) cout<<"1000";
	else if(ump[x1]^ump[x2]) cout<<"1100";
	else if(abs((int)x1-x2)!=1) cout<<"1110";
	else cout<<"1111";
	return 0;
}
