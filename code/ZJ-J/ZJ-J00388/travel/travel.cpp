#include<bits/stdc++.h>
using namespace std;
string s1,s2;
char a,b;
int x,y;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	int c1,c2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		for(int i=0;i<2;i++){
			x=x*10+s1[i]-'0';
			y=y*10+s2[i]-'0';
		}
		a=s1[2],b=s2[2];
		if(x==y){
			cout<<1;
			if((a>='D'&&b>='D')||(a<'D'&&b<'D')){
				cout<<1;
				if(abs(a-b)==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
}