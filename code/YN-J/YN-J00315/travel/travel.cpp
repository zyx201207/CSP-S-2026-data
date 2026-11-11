#include<bits/stdc++.h>
//#define int long long
#define ll long long
using namespace std;
string c1,s1,c2,s2;

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	for(int i=0;i<=(int)c1.size();i++){
		if(c1[i]!=c2[i]){
			cout<<"0000";
			return 0;
		}
		
	}
	cout<<"1";
	for(int i=0;i<(int)s1.size()-1;i++){
		if(s1[i]!=s2[i]){
			cout<<"000";
			return 0;
		}
	}
	cout<<"1";
	if(s1[s1.size()-1]>='A'&&s1[s1.size()-1]<='C'){
		if(s2[s2.size()-1]>='D'&&s2[s2.size()-1]<='F'){
			cout<<"00";
			return 0;
		}
	}
	cout<<1;
	if(s1[s1.size()-1]+1!=s2[s2.size()-1]&&s1[s1.size()-1]-1!=s2[s2.size()-1]){
		cout<<"0";
		return 0;
	}
	cout<<1;
	return 0;
}
