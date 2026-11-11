#include<bits/stdc++.h>
using namespace std;
//#define int long long  
const int N=1e5+5;
int a,b;
string s,p;
int mp[2000];
bool check(string s,string k,char c,char r){
	int u=(s[0]-'0')*10+s[1]-'0';
	int v=(k[0]-'0')*10+k[1]-'0';
	if(c=='F')c='E';
	if(r=='F')r='E';
	if(u==v){
		return ((abs(int(c)-int(r))<=1)&&(mp[c]==mp[r]));
	}else return 0;
	
}
string num1,num2;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0); 
	
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	cin>>a>>s>>b>>p;
	
	mp['A']=mp['B']=mp['C']=1;
	mp['D']=mp['F']=2;
	num1=(num1+s[0]+s[1]),num2=(num2+p[0]+p[1]);
	
	char t1=s[2],t2=p[2];
	cout<<(a==b);
	cout<<((a==b)&&(num1==num2));
	
	cout<<((a==b)&&(num1==num2)&&(mp[t1]==mp[t2]));
	
	cout<<((a==b)&&check(num1,num2,t1,t2));
	return 0;
}//02 01C 02 01A
