#include<bits/stdc++.h> 
using namespace std;
int c1,c2,s1,s2;
char c,p,q;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1;
	cin>>c;
	s1+=c-'0';
	cin>>c;
	s1=s1*10+c-'0';
	cin>>p;
	cin>>c2;
	cin>>c;
	s2+=c-'0';
	cin>>c;
	s2=s2*10+c-'0';
	cin>>q;
	cout<<(c1==c2);
	cout<<(c1==c2&&s1==s2);
	cout<<(c1==c2&&s1==s2&&(((p>='A'&&p<='C')&&(q>='A'&&q<='C'))||((p=='D'||p=='F')&&(q=='D'||q=='F'))));
	cout<<(c1==c2&&s1==s2&&((p>='A'&&p<='C')&&(q>='A'&&q<='C')&&abs(p-q)==1)||((p=='D')&&(q=='F'))||((q=='D')&&(p=='F')));
	return 0;
}
