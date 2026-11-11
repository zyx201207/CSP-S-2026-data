#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false),cin.tie(0),cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1.substr(0,2)==s2.substr(0,2)){
			cout<<1;
			bool f1,f2;
			string k1=s1.substr(2,1),k2=s2.substr(2,1);
			if(k1=="D"||k1=="F") f1=1;
			else f1=0;
			if(k2=="D"||k1=="F") f2=1;
			else f2=0;
			if(f1==f2){
				cout<<1;
				bool o=0;
				if(f1==1&&f2==1) o=1;
				else if(f1==0&&f2==0){
					if((k1=="A"&&k2=="B")||(k1=="B"&&k2=="A")) o=1;
					else if((k1=="B"&&k2=="C")||(k1=="C"&&k2=="B")) o=1;
				}
				cout<<o;
			}
			else{
				cout<<"00";
				return 0;				
			}
		}
		else{
			cout<<"000";
			return 0;
		}
	}
	else{
		cout<<"0000";
		return 0;
	}
	return 0;
}

