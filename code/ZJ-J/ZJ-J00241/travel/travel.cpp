#include<bits/stdc++.h>
using namespace std;
string c1,c2,s1,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>c2>>s1>>s2;
	if(c1==s1) cout<<1;
	else{ cout<<"0000\n"; return 0; }
	if(c2[0]==s2[0]&&c2[1]==s2[1]) cout<<1;
	else{ cout<<"000\n"; return 0; }
	if((c2[2]-'A'+1<=3&&s2[2]-'A'+1>3)||(s2[2]-'A'+1<=3&&c2[2]-'A'+1>3)){ cout<<"00\n"; return 0; }
	else cout<<1;
	if(c2[2]+1==s2[2]||s2[2]+1==c2[2]) cout<<1<<"\n";
	else cout<<0<<"\n";
	return 0;
}
