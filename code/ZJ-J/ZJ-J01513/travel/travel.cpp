#include<bits/stdc++.h>
using namespace std;
string c1,c2,c3,c4;
map<char,map<char,bool>>vis;
map<char,map<char,bool>>v;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	vis['A']['B']=1;
	vis['B']['C']=1;
	vis['C']['A']=1;
	vis['D']['F']=1;
	v['A']['B']=1;
	v['B']['C']=1;
	v['D']['F']=1;
	cin>>c1>>c2>>c3>>c4;
	if(c1==c3)cout<<1;
	else return (cout<<"0000",0);
	string p1=c2.substr(0,2);
	string p2=c4.substr(0,2);
	if(p1==p2)cout<<1;
	else return (cout<<"000",0);
	char pos1=c2[c2.size()-1],pos2=c4[c4.size()-1];
	if(vis[pos1][pos2]||vis[pos2][pos1])cout<<1;
	else return (cout<<"00",0);
	if(v[pos1][pos2]||v[pos2][pos1])cout<<1;
	else cout<<0;
	return 0;
}