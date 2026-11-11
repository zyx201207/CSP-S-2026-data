#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
map<char,int> mp;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	mp['A']=1;
	mp['B']=2;
	mp['C']=3;
	mp['D']=4;
	mp['E']=5;
	if(a!=c){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(b[0]!=d[0]||b[1]!=d[1]){
		cout<<"000";
		return 0;
	}
	cout<<1;
	if(b[2]<='C'&&d[2]<='C'||b[2]>='D'&&d[2]>='D') cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(abs(mp[b[2]]-mp[d[2]])==1) cout<<1;
	else cout<<0; 
   	return 0;
}
//zhang zhong xing huo,cheng liao yuan fen tian zhi shi 
//掌中星火，成燎原焚天之势
