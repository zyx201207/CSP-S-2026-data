#include<bits/stdc++.h>
using namespace std;
int a,b;
char r[10],x[10];
signed main(){
    freopen("travel.in","r",stdin);
    freopen("travel.out","w",stdout);
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    cin>>a>>r>>b>>x;
    if(a!=b){
		cout<<"0000"<<'\n';
		return 0;
	}else cout<<1;
	if(r[0]!=x[0]||r[1]!=x[1]){
		cout<<"000"<<'\n';
		return 0;
	}else cout<<1;
	if((r[2]=='D'&&x[2]!='F')||(r[2]=='F'&&x[2]!='D')||(x[2]=='D'&&r[2]!='F')||(x[2]=='F'&&r[2]!='D')){
	    cout<<"00"<<'\n';
	    return 0;
	}else cout<<1;
	if((r[2]=='A'&&x[2]=='B')||(r[2]=='C'&&x[2]=='B')||(r[2]=='D'&&x[2]=='F')||(x[2]=='A'&&r[2]=='B')||(x[2]=='C'&&r[2]=='B')||(x[2]=='D'&&r[2]=='F')) cout<<1<<'\n';
	else cout<<0<<'\n';
    return 0;
}
