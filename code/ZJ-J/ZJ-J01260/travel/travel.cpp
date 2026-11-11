#include<bits/stdc++.h>
using namespace std;
string r,rt,x,xt;
//AC on 8:50 也太久了
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>r>>rt>>x>>xt;
	if(r==x){
		cout<<1;
		if(rt[0]==xt[0]&&rt[1]==xt[1]){
			cout<<1;
			if((rt[2]=='A'||rt[2]=='B'||rt[2]=='C')&&(xt[2]=='A'||xt[2]=='B'||xt[2]=='C')||(rt[2]=='D'||rt[2]=='F')&&(xt[2]=='D'||xt[2]=='F')){
				cout<<1;
				if((rt[2]=='A'||rt[2]=='B')&&(xt[2]=='A'||xt[2]=='B')||(rt[2]=='C'||rt[2]=='B')&&(xt[2]=='C'||xt[2]=='B')||(rt[2]=='D'||rt[2]=='F')&&(xt[2]=='D'||xt[2]=='F'))cout<<1;
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<"0000";
	return 0;
}
