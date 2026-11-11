#include<bits/stdc++.h>
using namespace std;
int a,s,d,f;
char q,w;
bool b,b2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>d>>q>>s>>f>>w;
	if(a!=s){
		cout<<"0000";
		return 0;
	}
	cout<<1;
	if(d!=f){
		cout<<"000";
		return 0;
	}
	cout<<1;
	b=((q-'A')<3);
	b2=((w-'A')<3);
	if(b!=b2){
		cout<<"00";
		return 0;
	}
	cout<<1;
	if(q=='F')q='E';
	if(w=='F')w='E';
	if(abs(q-w)!=1){
		cout<<"0";
		return 0;
	}
	cout<<1;
	return 0;
}
/*
//9:02!
请问Trick||Treat!是啥东西啊
忽悠我and差点写了|| 
*/
