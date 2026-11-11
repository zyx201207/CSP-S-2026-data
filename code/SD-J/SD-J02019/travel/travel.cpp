#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string a,b,c,d;
	bool f=1;
	cin>>a>>b>>c>>d;
	int a1=0,c1=0;
	for(int i=0;i<a.size();i++) a1=a1*10+(a[i]-'0');
	for(int i=0;i<c.size();i++) c1=c1*10+(c[i]-'0');
	if(a1==c1&&f==1){
		cout<<1;
	}
	else cout<<0,f=0;
	int b1=0,d1=0;
	for(int i=0;i<b.size()-1;i++) b1=b1*10+(b[i]-'0');
	for(int i=0;i<d.size()-1;i++) d1=d1*10+(d[i]-'0');
	if(b1==d1&&f==1){
		cout<<1;
	}
	else cout<<0,f=0;
	int f1=0,f2=0;
	if(b[2]=='A'||b[2]=='B'||b[2]=='C') f1=1;
	if(b[2]=='D'||b[2]=='F') f1=0;
	if(d[2]=='A'||d[2]=='B'||d[2]=='C') f2=1;
	if(d[2]=='D'||d[2]=='F') f2=0;
	if(f1==f2&&f==1) cout<<1;
	else cout<<0,f==0;
	char s1=b[2],s2=d[2];
	if(s1=='A'||s1=='B'||s1=='C'){
		if(s1=='C'){
			if(s2=='B'&&f==1) cout<<1;
			else cout<<0;
		}
		else if(s1=='A'||s1=='B'){
			if(s1=='A'){
				if(s2=='B'&&f==1) cout<<1;
				else cout<<0; 
			}
			else if(s1=='B'){
				if((s2=='A'||s2=='C')&&f==1) cout<<1;
				else cout<<0;
			}
			
		}
	}
	else if(s1=='D'||s1=='F'){
		if(s1=='D'){
			if(s2=='F'&&f==1) cout<<1;
			else cout<<0;
		}
		else{
			if(s2=='D'&&f==1) cout<<1;
			else cout<<0;
		}
	}
	return 0;
}
//shi shan dai ma
