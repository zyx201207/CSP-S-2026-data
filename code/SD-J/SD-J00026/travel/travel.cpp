#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int a[255],b[255];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	a['F']=1;
	a['D']=1;
	a['C']=2;
	a['B']=2;
	a['A']=2;
	b['F']=1;
	b['D']=2;
	b['C']=4;
	b['B']=5;
	b['A']=6;
	cin>>c1>>s1>>c2>>s2;
	bool aa=(c1==c2);
	bool bb=aa&&((s1[0]==s2[0])&&
	s1[1]==s2[1]);
	bool cc=bb&&(a[s1[2]]==a[s2[2]]);
	bool dd=cc&&
	(abs(b[s1[2]]-b[s2[2]])==1);
	cout<<aa<<bb<<cc<<dd;
	return 0;
}
