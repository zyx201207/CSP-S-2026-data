#include<bits/stdc++.h>
using namespace std;

int a,b,c,d;
string p,q;
bool check(char s,char t){
	if(s>t)swap(s,t);
	if(s=='D'&&t=='F')return 1;
	if(s=='A'&&t=='B')return 1;
	if(s=='B'&&t=='C')return 1;
	return 0;
}
bool che(char s,char t){
	if(s>t)swap(s,t);
	if((s=='A'||s=='B'||s=='C')&&(t=='A'||t=='B'||t=='C'))return 1;
	if((s=='D'||s=='F')&&(t=='D'&&t=='F'))return 1;
	return 0;
}
signed main(){ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>p>>b>>q;
	c=(p[0]-'0')*10+p[1]-'0',d=(q[0]-'0')*10+(q[1]-'0');
	int w=(a==b),x=(c==d)&&w,y=che(p[2],q[2])&&x&&w,z=check(p[2],q[2])&&x&&y&&w;
	cout<<w<<x<<y<<z<<'\n';
	return 0;
}
