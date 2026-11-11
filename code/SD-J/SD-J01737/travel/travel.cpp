#include<bits/stdc++.h>
using namespace std;
map<string,int> mp;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string A="A",B="B",C="C",D="D",F="F";
	mp[A]=1,mp[B]=1,mp[C]=1,mp[D]=2,mp[F]=2;
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	int a1=0,b1=0,c3=0,d1=0;
	if(c1==c2){
		a1=1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			b1=1;
			string sa=s1.substr(2,1),sb=s2.substr(2,1);
			if(mp[sa]==mp[sb]){
				c3=1;
				if(sa=="A"&&sb=="B"||sa=="B"&&sb=="A"||sa=="B"&&sb=="C"||sa=="C"&&sb=="B"||sa=="D"&&sb=="F"||sa=="F"&&sb=="D"){
					d1=1;
				}
				else{
					d1=0;
				}
			}
			else{
				c3=0;
			}
		}
		else b1=0;
		cout<<a1<<b1<<c3<<d1; 
	}
	else cout<<"0000";
	return 0;
}
