#include<bits/stdc++.h>
using namespace std;
#define int long long

signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int a,b;string s1,s2;
	cin>>a>>s1>>b>>s2;
	char u=s1[2],v=s2[2];
	int x=(s1[0]-'0')*10+(s1[1]-'0'),y=(s2[0]-'0')*10+(s2[1]-'0');
//	cout<<a<<" "<<x<<" "<<u<<"\n"<<b<<" "<<y<<" "<<v<<"\n";
	if(a==b){
		cout<<1;
		if(x==y){
			cout<<1;
			if(u<='C'&&v<='C'||u>='D'&&v>='D'){
				cout<<1;
				if(abs(u-v)<=1)cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}

