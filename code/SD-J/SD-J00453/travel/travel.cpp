#include<bits/stdc++.h>
using namespace std;
int c1,c2;
string s1,s2;
bool check1(string S1,string S2)       //ÅÅ 
{
	if(s1[0]!=s2[0]) return false;
	else if(s1[1]!=s2[1]) return false;
	else return true;
}
bool check2(string s1,string s2)      //Ò»²à 
{
	if((s1[2]=='D' || s1[2]=='F') && (s2[2]=='A' || s2[2]=='B' || s2[2]=='C')) return false;
	else if((s2[2]=='D' || s2[2]=='F') && (s1[2]=='A' || s1[2]=='B' || s1[2]=='C')) return false;
	else return true;
}	
bool check3(string s1,string s2)     //°¤×Å
{
	if(s1[2]=='D' || s2[2]=='D') return true;
	else if(s1[2]=='B' || s2[2]=='B') return true;
	else false;
} 
int main()
{
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	cin>>c1>>s1;
	cin>>c2>>s2;
	if(c1!=c2) cout<<"0000"<<endl;
	else if(!check1(s1,s2)) cout<<"1000"<<endl;
	else if(!check2(s1,s2)) cout<<"1100"<<endl;
	else if(!check3(s1,s2)) cout<<"1110"<<endl;
	else cout<<"1111"<<endl;
	return 0;
}
