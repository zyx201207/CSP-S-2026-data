#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,c2,s1,s2;
map<char,bool> mp1;
map<char,int> mp2;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	mp1['A']=0;
	mp1['B']=0;
	mp1['C']=0;
	mp1['D']=1;
	mp1['F']=1;
	mp2['A']=1;
	mp2['B']=2;
	mp2['C']=3;
	mp2['D']=4;
	mp2['F']=5;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(mp1[s1[2]]==mp1[s2[2]]){
				cout<<1;
				int i1=mp2[s1[2]],i2=mp2[s2[2]];
				if(i1<i2){
					int t=i1;
					i1=i2;
					i2=t;
				}
				if(i1-i2==1){
					cout<<1;
				}else{
					cout<<"0";
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
