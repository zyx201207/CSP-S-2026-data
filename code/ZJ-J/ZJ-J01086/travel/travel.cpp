#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	int s1=0,s2=0;
	for(int i=0;i<a.size();i++) s1=s1*10+(a[i]-'0');
	for(int i=0;i<c.size();i++) s2=s2*10+(c[i]-'0');
	if(s1!=s2) cout<<"0000";
	else{
		if(b[0]!=d[0]||b[1]!=d[1]) cout<<"1000";
		else{
			if(b[2]>='A'&&b[2]<='C'&&d[2]>='A'&&d[2]<='C'||b[2]>='D'&&b[2]<='F'&&d[2]>='D'&&d[2]<='F'){
				if(b[2]=='A'&&d[2]=='B'||b[2]=='B'&&d[2]=='C'||b[2]=='D'&&d[2]=='F') cout<<"1111";
				else cout<<"1110";
			}
			else cout<<"1100";
		}
	}
	return 0;
}
