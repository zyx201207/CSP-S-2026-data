#include<bits/stdc++.h>
using namespace std;
int c1,c2,sa,sb;
char s1[10],s2[10];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
    cin>>c1;
	for(int i=1;i<=3;i++){
		cin>>s1[i];
	}
	sa=(s1[1]-'0')*10+(s1[2]-'0');
	cin>>c2;
	for(int i=1;i<=3;i++){
		cin>>s2[i];
	}
	sb=(s2[1]-'0')*10+(s2[2]-'0');
	if(c1==c2)cout<<1;
	else cout<<0;
	if(c1==c2&&sa==sb)cout<<1;
	else cout<<0;
	if(c1==c2&&sa==sb&&((s1[3]>='A'&&s2[3]<='C')
	||((s1[3]=='D'&&s2[3]=='F')||(s2[3]=='D'&&s1[3]=='F'))))cout<<1;
	else cout<<0;
	if(c1==c2&&sa==sb&&(s1[3]>='A'&&s2[3]<='C')){
		if(((s1[3]-'A')-(s2[3]-'A')==1)||((s1[3]-'A')-(s2[3]-'A')==-1))cout<<1;
		else cout<<0;
	}	
	else if(c1==c2&&sa==sb&&((s1[3]=='D'&&s2[3]=='F')||(s2[3]=='D'&&s1[3]=='F')))cout<<1;
	else cout<<0;
	return 0;
}//((((s1[3]-'A')-(s2[3]-'A')==1)||((s1[3]-'A')-(s2[3]-'A')==-1))
//	&&((s1[3]>='A'&&s2[3]<='C')||(s1[3]>='D'&&s2[3]<='F')))cout<<1;