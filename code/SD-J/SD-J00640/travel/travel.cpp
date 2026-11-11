#include<bits/stdc++.h>
using namespace std;
const int N=1e6+10;
string cr,cx,sr,sx;
int c,s,a,b;
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>cr>>sr>>cx>>sx;
	for(int i=0;i<2;i++){
		if(cr[i]!=cx[i]){
			c=1;
			break;
		}
	}
	if(c==1){
		cout<<"0000";
		return 0;
	}
	for(int i=0;i<2;i++){
		if(sr[i]!=sx[i]){
			s=1;
			break;
		}
	}
	if(s==1){
		cout<<"1000";
		return 0;
	}
	a=int(sr[2]-'A'+1);
	b=int(sx[2]-'A'+1);
	if((b>=4&&a<=3)||(a>=4&&b<=3)){
		cout<<"1100";
		return 0;
	}
	if((a==4&&b==6)||(a==6&&b==4)){
		cout<<"1111";
		return 0;
	}
	if(abs(a-b)>1){
		cout<<"1110";
		return 0;
	}
	cout<<"1111";
	return 0;
}
