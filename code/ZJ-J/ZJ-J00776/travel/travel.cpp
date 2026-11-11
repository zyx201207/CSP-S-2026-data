#include<bits/stdc++.h>
using namespace std;
int n;string c1,s1,c2,s2;
int c(char s){
	if(s<='C') return 1;
	else return 0;
}int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1; else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]) cout<<1; else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&c(s1[2])==c(s2[2])) cout<<1; else cout<<0;
	if(c1==c2&&s1[0]==s2[0]&&s1[1]==s2[1]&&c(s1[2])==c(s2[2])&&(abs(s1[2]-s2[2])==1||(c(s1[2])==0&&s1[2]!=s2[2]))) cout<<1;
	else cout<<0;
}