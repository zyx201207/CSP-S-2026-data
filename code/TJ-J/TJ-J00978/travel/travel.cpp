#include<bits/stdc++.h>
using namespace std;
struct p{
	int c;
	string s;
};
string s1;
p x;
p r;
int cnt0,cnt,cnt1;
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r.c;
	cin>>r.s;
	cin>>x.c;
	cin>>x.s;
	
	if(r.c==x.c){
	s1+='1';
	cnt0++;
	}
	else s1+='0';
	
	if(cnt0&&(r.s[1]==x.s[1]&&r.s[0]==x.s[0])){
	s1+='1';
	cnt++;
	}
	else s1+='0';
	
	
	if(cnt&&(r.s[2]<=67&&x.s[2]<=67)||(r.s[2]>67&&x.s[2]>67)){
	s1+='1';
	cnt1++;
	}
	else s1+='0';
	
	if(cnt1&&(abs(r.s[2]-x.s[2])==1)){
	s1+='1';
	}
	else s1+='0';
	cout<<s1;
	return 0;
}
