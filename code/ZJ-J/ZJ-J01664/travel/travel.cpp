#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f(char a,char b){
	bool aa=1,bb=1;
	if(a=='A'||a=='B'||a=='C'){
		aa=0;
	}
	if(b=='A'||b=='B'||b=='C'){
		bb=0;
	}
	return (aa==bb);
};
int main(){
	ios::sync_with_stdio(0),cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		cout<<(s1[0]==s2[0]&&s1[1]==s2[1]);
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<f(s1[2],s2[2]);
			if(!f(s1[2],s2[2])){
				cout<<0;
				return 0;
			}
			else{
				cout<<(abs(int(s1[2])-int(s2[2]))==1);
			}
		}
		else{
			cout<<0;
			cout<<0;
		}
	}
	else{
		cout<<"0000";
	}
}