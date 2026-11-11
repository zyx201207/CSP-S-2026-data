#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+5;
int a,b,c,d;
string c1,s1,c2,s2;
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	a=(c1[0]-'0')*10+(c1[1]-'0');
	b=(s1[0]-'0')*10+(s1[1]-'0');
	c=(c2[0]-'0')*10+(c2[1]-'0');
	d=(s2[0]-'0')*10+(s2[1]-'0');
	int e=(s1[2]<='D'?s1[2]-'A':4)+1;
	int f=(s2[2]<='D'?s2[2]-'A':4)+1;
	if(a==b){
		cout<<1;
		if(b==d){
			cout<<1;
			if((e<=3&&f<=3)||(e>3&&f>3)){
				cout<<1;
				if(abs(e-f)==1){
					cout<<1;
				}else cout<<"0";
			}else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	return 0;
}
