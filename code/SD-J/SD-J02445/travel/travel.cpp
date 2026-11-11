#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool f(char x,char y){
	if(x=='C'&&y=='D')return false;
	return true;
}
int main(){
	ios::sync_with_stdio(false);cin.tie(0);cout.tie(0);
	freopen("travel1.in","r",stdin);
	freopen("travel1.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<1;
			if(!(s1[2]<='C' ^ s2[2]<='C')){
				cout<<1;
				cout<<(abs(s1[2]-s2[2])==1);
			}else {
				cout<<0<<0;
			}
		}else cout<<"000";
	}else
	cout<<"0000";
	return 0;
} 
