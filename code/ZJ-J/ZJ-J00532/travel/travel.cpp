#include<bits/stdc++.h>
using namespace std;
#define int long long
string a,b,c,d;
map<char,int>ma;
map<pair<char,char>,int>mp;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    cin>>a>>b>>c>>d;
    ma['A']=1;
    ma['B']=1;
    ma['C']=1;
    ma['D']=2;
    ma['F']=2;
    mp[{'A','B'}]=1;
    mp[{'B','C'}]=1;
    mp[{'B','A'}]=1;
    mp[{'C','B'}]=1;
    mp[{'D','F'}]=1;
    mp[{'F','D'}]=1;
    if(a!=c){
    	cout<<"0000";
	}
	else if(!(b[0]==d[0]&&b[1]==d[1])){
		cout<<"1000";
	}
	else if(ma[b[2]]!=ma[d[2]]){
		cout<<"1100";
	}
	else if(mp[{b[2],d[2]}]==0){
		cout<<"1110";
	}
	else{
		cout<<"1111";
	}
	return 0;
}