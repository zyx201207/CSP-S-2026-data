#include<bits/stdc++.h>
using namespace std;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int n=4;
	int c1,c2;
	string s1,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		n--;
		if(s1[0]==s2[0]||s1[1]==s2[1]){
			cout<<1;
			n--;
			if((s1[2]>='A'&&s1[2]<='C'&&s2[2]>='A'&&s2[2]<='C')||(s1[2]>='D'&&s1[2]<='F'&&s2[2]>='D'&&s2[2]<='F')){
				cout<<1;
				n--;
				if(s1[2]-'a'+'b'==s2[2]||s1[2]==s2[2]-'a'+'b'||s1[2]+'a'-'b'==s2[2]){
					cout<<1;
					n--;
				}
			}
		}
	}
	for(int i=1;i<=n;i++){
		cout<<0;
	}
	return 0;
}
