#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool flag=1;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) flag=0;
	cout<<flag;
	if(s1[0]!=s2[0] || s1[1]!=s2[1]) flag=0;
	cout<<flag;
	if(s1[2]<='C' ^ s2[2]<='C') flag=0;
	cout<<flag;
	if(((s1[2]=='D' && s2[2]=='F') || (s1[2]=='F' && s2[2]=='D')) && flag) flag=1;
	else if(abs(s1[2]-s2[2])!=1) flag=0;
	cout<<flag<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
