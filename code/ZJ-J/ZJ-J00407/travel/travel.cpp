#include<bits/stdc++.h>
using namespace std;
int a,a1,b,b1;
char s1,s2;
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>a1>>s1>>b>>b1>>s2;
	if(a==b){
		cout<<"1";
		if(a1==b1){
			cout<<"1";
			if(s1>s2)swap(s1,s2);
			if(s1<='C'&&s2>='D')cout<<"00";
			else{
				cout<<"1";
				if(s1=='A'&&s2=='C')cout<<"0";
				else cout<<"1";
			}
		}
		else cout<<"000";
	}
	else cout<<"0000";
	 
	return 0;
} 
