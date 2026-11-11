#include<bits/stdc++.h>
using namespace std;
#define int long long
map<char,int>mp;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	
	mp['A']=1,mp['B']=2,mp['C']=3,mp['D']=4,mp['F']=5;
	int x,y;
	string s1,s2;
	
	cin >> x >> s1 >> y >> s2;
	int a=(s1[0]-'0')*10+(s1[1]-'0'),b=(s2[0]-'0')*10+(s2[1]-'0');
	if(x==y) cout << 1;
	else{
		for(int i=1;i<=4;i++) cout << 0;
		return 0;
	}
	if(a==b) cout << 1;
	else{
		for(int i=1;i<=3;i++) cout << 0;
		return 0;
	}
	char c1=s1[2],c2=s2[2];
	if(c1>c2) swap(c1,c2);
	char op1=mp[c1],op2=mp[c2];
	if((op1==1 && op2==2)||(op1==1&&op2==3)||(op1==2&&op2==3)||(op1==4&&op2==5)){
		cout << 1;
	}
	else{
		cout << 0 << 0;
		return 0;
	}
	if((op1==1 && op2==2)||(op1==2&&op2==3)||(op1==4&&op2==5)){
		cout << 1;
	}
	else cout << 0;
	return 0;
}

