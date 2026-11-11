#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int f(char c){
	if(c=='A'||c=='B'||c=='C')return 0;
	else return 1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin.tie(0)->sync_with_stdio(0);
	cin>>c1>>s1>>c2>>s2;
	cout<<(c1==c2);
	cout<<((c1==c2)&&(s1[0]==s2[0])&&(s1[1]==s2[1]));
	cout<<((c1==c2)&&(s1[0]==s2[0])&&(s1[1]==s2[1])&&(f(s1[2])==f(s2[2])));
	cout<<((c1==c2)&&(s1[0]==s2[0])&&(s1[1]==s2[1])&&(f(s1[2])==f(s2[2]))&&(abs(s1[2]-s2[2])==1));
	return 0;
}
