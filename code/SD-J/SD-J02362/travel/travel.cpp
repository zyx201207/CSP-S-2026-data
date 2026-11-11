#include<bits/stdc++.h>
using namespace std;
#define int long long
string a1;
string a2;
string b1;
string b2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1){
		cout<<"1";
		int sum=0;
		for(int i=0;i<a2.size()-1;i++){
			if(a2[i]==b2[i]) sum++;
		}
		if(sum==2){
			cout<<"1";
			for(int i=2;i<a2.size();i++){
			if((a2[i]=='A'&&b2[i]=='B')||(a2[i]=='A'&&b2[i]=='C')||(a2[i]=='B'&&b2[i]=='C')||(a2[i]=='B'&&b2[i]=='A')||(a2[i]=='C'&&b2[i]=='B')||(a2[i]=='C'&&b2[i]=='A')) cout<<"1";
			else if((a2[i]=='E'&&b2[i]=='D')||(a2[i]=='D'&&b2[i]=='E')) cout<<"1";
			else cout<<"0";
		}
			for(int i=2;i<a2.size();i++){
				if((a2[i]=='A'&&b2[i]=='B')||(a2[i]=='B'&&b2[i]=='C')||(a2[i]=='B'&&b2[i]=='A')||(a2[i]=='C'&&b2[i]=='B')) cout<<"1";
				else if((a2[i]=='E'&&b2[i]=='D')||(a2[i]=='D'&&b2[i]=='E')) cout<<"1";
				else cout<<"0";
			}
		}
		else cout<<"000";
	}
	
	else cout<<"0000";
	
	return 0;
} 
