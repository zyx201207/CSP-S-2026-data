#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
bool pd(string s0){
	if(s0[2]=='A' || s0[2]=='B' || s0[2]=='C') return 1;
	else return 0;
}
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0] && s1[1]==s2[1]){
			cout<<1;
			if(pd(s1)== pd(s2)){
				cout<<1;
				if(pd(s1)==0) cout<<1<<"c";
				else if(pd(s1)==1){
					if(s1[2]-1==s2[2] || s1[2]+1==s2[2]){
						cout<<1;
					}
					else cout<<0;
				}
			}
			else cout<<0<<0;
		}
		else cout<<0<<0<<0;
	}
	else cout<<0<<0<<0<<0;
	return 0;
} 
