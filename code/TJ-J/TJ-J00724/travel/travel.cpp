#include <bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int ans=0,cnt=0;
	int a[20]={},b[20]={},d[20]={},e[20]={};
	for(int i=0;i<c1.lenth()){
		if(c1[i]>='0' && c1[i]<='9'){
			a[i+1]=c1[i]-'0';
		}
		if(c2[i]>='0' && c2[i]<='9'){
			b[i+1]=c2[i]-'0';
		}
	}
	for(int i=0;i<s1.lenth()){
		if(s1[i]>='0' && s1[i]<='9'){
			d[i+1]=s2[i]-'0';
		}
		if(s2[i]>='0' && s2[i]<='9'){
			e[i+1]=s2[i]-'0';
		}
	}
	ans+=a[1]*10+a[2];
	cnt+=b[1]*10+b[2];
	int g1=0,g2=0,g3=0;
	if(ans==cnt)g1=1;
	int s=0,f=0;
	s+=d[1]*10+d[2];
	f+=e[1]*10+e[2];
	if(s==f)g2=1;
	int g4=0;
	for(int i=0;i<s1.lenth()){
		if(s1[i]<='0' || s1[i]>='9'){
			string q=s1[i];
		}
		if(s2[i]<='0' || s2[i]>='9'){
			string p=s2[i];
		}
		if((q[i]=='A' && p[i]=='B')||(q[i]=='B' && p[i]=='C')||(q[i]=='D' && p[i]=='F')||(q[i]=='B' && p[i]=='A')||(q[i]=='C' && p[i]=='B')||(q[i]=='F' && p[i]=='D'))g3=1;
		if((q[i]=='A' && p[i]=='B')||(q[i]=='A' && p[i]=='C')||(q[i]=='B' && p[i]=='C')||(q[i]=='D' && p[i]=='F')||(q[i]=='B' && p[i]=='A')||(q[i]=='C' && p[i]=='B')||(q[i]=='C' && p[i]=='A')||(q[i]=='F' && p[i]=='D')){
			g4=1;
		}
	}
	if(g1==1)cout<<'1';
	else cout<<'0';
	if(g2==1)cout<<'1';
	else cout<<'0';
	if(g3==1)cout<<'1';
	else cout<<'0';
	if(g4==1)cout<<'1';
	else cout<<'0';
	return 0;
}
