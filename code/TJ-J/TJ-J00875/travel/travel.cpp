#include<bits/stdc++.h>
using namespace std;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1[0]==c2[0]&&c1[1]==c2[1]){
		cout<<"1";
		if(s1[0]==s2[0]&&s1[1]==s2[1]){
			cout<<"1";
			int c3=s1[2]-'A'+65;
			int c4=s2[2]-'A'+65;
			if((c3<=67&&c4<=67)||(c3>67&&c4>67)){
				cout<<"1";
				if(c3>c4){
					int c5=c3;
					c3=c4;
					c4=c5;
				}
				if((c4-1)==c3) cout<<"1";
				else cout<<"0";
			}
			else cout<<"00";
		}
		else cout<<"000";
	}
	else cout<<"0000";
	return 0;
} 
