#include<bits/stdc++.h>
#define int long long
using namespace std;
signed main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int x,y;
	string s1,s2;
	cin>>x>>s1>>y>>s2;
	char h1=s1[s1.size()-1],h2=s2[s2.size()-1];
	string l1=s1.substr(0,2),l2=s2.substr(0,2);
	int x1=stoll(l1),x2=stoll(l2);
	string s;
	if(x==y){
		s+='1';
		if(x1==x2){
			s+='1';
			if(h1=='A'&&(h2=='B'||h2=='C')||h1=='B'&&(h2=='A'||h2=='C')||h1=='C'&&(h2=='A'||h2=='B')||h1=='D'&&h2=='F'||h1=='F'&&h2=='D'){
				s+='1';
				if(h1=='A'&&h2=='B'||h1=='B'&&(h2=='A'||h2=='C')||h1=='C'&&h2=='B'||h1=='D'&&h2=='F'||h1=='F'&&h2=='D'){
					s+='1';
				}else{
					s+='0';
				}
			}else{
				s+="00";
			}
		}else{
			s+="000";
		}
	}else{
		s="0000";
	}
	cout<<s;
	return 0;
}
