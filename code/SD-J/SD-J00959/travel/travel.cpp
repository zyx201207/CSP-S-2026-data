#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string s1,s2,s11,s22;
ll f(string s){
	ll s1=(s[0]-'0')*10+(s[1]-'0');
	return s1;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>s1>>s2>>s11>>s22;
	if (s1==s11) cout<<1;
	else cout<<0;
	if((s1==s11)&&(f(s2)==f(s22))) cout<<1;
	else cout<<0;
	if((s1==s11)&&(f(s2)==f(s22))&&((s2[2]>='A'&&s2[2]<='C'&&s22[2]>='A'&&s22[2]<='C')||(s2[2]>='D'&&s2[2]<='F'&&s22[2]>='D'&&s22[2]<='F'))) cout<<1;
	else cout<<0;
	if((s1==s11)&&(f(s2)==f(s22))&&((s2[2]>='A'&&s2[2]<='C'&&s22[2]>='A'&&s22[2]<='C')||(s2[2]>='D'&&s2[2]<='F'&&s22[2]>='D'&&s22[2]<='F'))&&(s2[3]-1==s22[2]||s2[2]+1==s22[2])) cout<<1;
	else cout<<0;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
