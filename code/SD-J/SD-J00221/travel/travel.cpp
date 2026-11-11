#include<bits/stdc++.h>
using namespace std;

int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int a,b;
	string s1,s2;
	cin>>a>>s1>>b>>s2;
	int c=(s1[0]-'0')*10+s1[1];
	int d=(s2[0]-'0')*10+s2[1];
	int x=s1[2]-'A';
	int y=s2[2]-'A';
	if(a!=b) cout<<"0000";
	else if(c!=d) cout<<"1000";
	else if((x<=2&&y>2)||(x>2&&y<=2)) cout<<"1100";
	else if(abs(x-y)>1) cout<<"1110";
	else cout<<"1111"; 
	return 0;
} 
