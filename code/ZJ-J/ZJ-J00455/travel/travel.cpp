#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e5+5;
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int x,y;
	string s1,s2;
	cin>>x>>s1>>y>>s2;
	if(x!=y)cout<<"0000";
	else{
		int xx=0;
		for(int i=0;i<2;i++){
			xx=xx*10+s1[i]-'0';
		}
		int yy=0;
		for(int i=0;i<2;i++){
			yy=yy*10+s2[i]-'0';
		}
		if(xx!=yy){
			cout<<"1000";
		}
		else{
			int a,b;
			if(s1[2]=='F'||s1[2]=='D'){
				a=1;
			}
			else{
				a=2;
			}
			if(s2[2]=='F'||s2[2]=='D'){
				b=1;
			}
			else{
				b=2;
			}
			if(a!=b)cout<<"1100";
			else{
				if(abs((int)(s1[2])-(int)(s2[2]))==1)cout<<"1111";
				else cout<<"1110";
			}
		}
	}
	return 0;
}
