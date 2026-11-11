#include <bits/stdc++.h>
using namespace std;
string c,s,cc,ss;
map <char,long long> a;
map <char,long long> b;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c>>s>>cc>>ss;
	a['A']=1;
	a['B']=1;
	a['C']=1;
	b['D']=1;
	b['F']=1;
	if(c==cc){
		cout<<1;
		if(s[0]==ss[0]&&s[1]==ss[1]){
			cout<<1;
			if((a.count(s[2])&&a.count(ss[2]))||(b.count(s[2])&&b.count(ss[2]))){
				cout<<1;
				if((s[2]=='A'&&ss[2]=='B')||(s[2]=='B'&&ss[2]=='A')||(s[2]=='C'&&ss[2]=='B')||(s[2]=='B'&&ss[2]=='C')||(s[2]=='D'&&ss[2]=='F')||(s[2]=='F'&&ss[2]=='D')){
				   cout<<1;
			    }else{
			       cout<<0;
				}
			}else{
				cout<<"00";
			}
		}else{
			cout<<"000";
		}
	}else{
		cout<<"0000";
	}
	return 0;
} 
