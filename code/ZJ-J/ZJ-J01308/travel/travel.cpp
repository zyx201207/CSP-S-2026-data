#include<bits/stdc++.h>
using namespace std;
char pw[200];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	pw['A']='B',pw['B']='C',pw['C']=0,pw['D']='F';pw['F']=1;
	ios::sync_with_stdio(0);cin.tie(0);
	string c1,s1,c2,s2;cin>>c1>>s1>>c2>>s2;
	if(c1==c2)cout<<"1";
	else cout<<"0";
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2))
		cout<<"1";
	else cout<<"0";
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&!((s1[2]<='C')^(s2[2]<='C')))
		cout<<"1";
	else cout<<"0";
	if(c1==c2&&s1.substr(0,2)==s2.substr(0,2)&&!((s1[2]<='C')^(s2[2]<='C'))&&(pw[s1[2]]==s2[2]||pw[s2[2]]==s1[2]))
		cout<<"1";
	else cout<<"0";
	cout<<'\n';
	return 0;
}
//8:42 100pts
