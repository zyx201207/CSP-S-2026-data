#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e6+10;
void fast_read(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0); 
}
string s,t;
int a,b;
int c,d;
char x,y;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	fast_read();
	cin>>a>>s>>c>>t;
	x=s[s.size()-1];
	y=t[t.size()-1];
	for(int i=0;i<s.size()-1;i++)
		b=b*10+(s[i]-'0');
	for(int i=0;i<t.size()-1;i++)
		d=d*10+(t[i]-'0');
	if(c!=a)cout<<"0000";
	else{
		cout<<1;
		if(b!=d)cout<<"000";
		else{
			cout<<1;
			if(abs(y-x)==1){
				if((y=='D'&&x=='C')||(y=='C'&&x=='D'))cout<<"00";
				else cout<<11;
			}
			else if((y=='F'&&x=='D')||(y=='D'&&x=='F'))cout<<11;
			else if((y=='A'&&x=='C')||(y=='C'&&x=='A'))cout<<10;
			else cout<<"00";
		}
	}
	return 0;
}
