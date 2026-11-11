#include<bits/stdc++.h>
#include<string>
using namespace std;
string s1,s2;
int a=0,b=0;
char a1,a2;
bool judge(char a,char b){
	if(((a>='A'&&a<='C')&&(b>='A' && b<='C')) || ((a>='D'&&a<='F')&&(b>='D' && b<='F'))) return true;
	return false;
}
int main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>s1>>a>>a1>>s2>>b>>a2;
    if(s1==s2) cout<<1;
    else cout<<0;
    if(s1==s2 && a==b) cout<<1;
    else cout<<0;
    if(s1==s2 && a==b && judge(a1,a2)) cout<<1;
    else cout<<0;
    if(s1==s2 && a==b &&judge(a1,a2) && (abs(a1-a2)==1 && ((a1!='D' && a2!='C') ||(a1!='C' && a2!='D')))) cout<<1;
    else cout<<0;
    return 0;
}
