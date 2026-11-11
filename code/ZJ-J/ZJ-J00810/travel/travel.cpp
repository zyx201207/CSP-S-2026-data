#include<bits/stdc++.h>
#define int long long
using namespace std;
string c1,s1,c2,s2;
int a[300];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	a['A']=1;a['B']=2;a['C']=3;a['D']=4;a['F']=5;
	if(c1==c2)cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	if(s1[0]==s2[0]&&s1[1]==s2[1])cout<<1;
	else{
		cout<<"000";
		return 0;
	}
	int x=a[s1[2]],y=a[s2[2]];
	if(x<=3&&y<=3||x>3&&y>3)cout<<1;
	else{
		cout<<"00";
		return 0;
	}
	if(!(x==3&&y==4)&&abs(x-y)==1)cout<<1;
	else cout<<0;
	return 0;
}