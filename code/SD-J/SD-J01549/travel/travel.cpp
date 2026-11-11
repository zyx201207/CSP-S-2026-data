#include<bits/stdc++.h>
using namespace std;
struct ticket{
	int c;
	string s;
};
ticket R,X;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>R.c>>R.s>>X.c>>X.s;
	if(R.c==X.c){
		cout<<"1";
		if(R.s[0]==X.s[0]&&R.s[1]==X.s[1]){
			cout<<"1";
			char rs=R.s[2],xs=X.s[2];
			if(rs<xs) swap(rs,xs);//±£Ö¤rs´ó
			if(rs<='C'){
				cout<<"1";
				if(rs==xs+1) cout<<"1";
				else cout<<"0";
			}else if(xs>='D') cout<<"11";
			else cout<<"00";
		}else cout<<"000";
	}else cout<<"0000";
	fclose(stdin);
	fclose(stdout);
	return 0;
}
