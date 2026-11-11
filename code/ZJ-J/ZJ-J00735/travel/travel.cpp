#include<bits/stdc++.h>
#include<string>
#include<vector>
#include<stack>
#include<queue>
#define ll long long
using namespace std;
string sx,cx,sy,cy;
map<ll,char> f;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>sx>>cx>>sy>>cy;
	f['A']=f['B']=f['C']=1;
	f['D']=f['E']=2;
	if(sx==sy){
		cout<<1;
		if(cx[0]==cy[0]&&cx[1]==cy[1]){
			cout<<1;
			if(f[cx[2]]==f[cy[2]]){
				cout<<1;
				char l=cx[2],r=cy[2];
				if(l>r) swap(l,r);
				if((l=='A'&&r=='B')||(l=='B'&&r=='C')||(l=='D'&&r=='E')) cout<<1;
				else cout<<0;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
}
