#include<bits/stdc++.h>
using namespace std;
#define int long long
const int N=1e3+10;
int c1,c2;
string s1,s2;
signed main(){
	ios::sync_with_stdio(0),cin.tie(0),cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2){
		cout<<"0000";
		return 0;
	}else{
		cout<<'1';
		bool f=1;
		for(int i=0;i<2;i++){
			if(s1[i]!=s2[i]){
				f=0;
			}
		}
		if(f==1){
			cout<<'1';
		}else{
			cout<<"000";
			return 0;
		}
		if(s1[2]<='F'&&s1[2]>='D'&&s2[2]<='F'&&s2[2]>='D'||s1[2]<='C'&&s1[2]>='A'&&s2[2]<='C'&&s2[2]>='A'){
			cout<<'1';
		}else{
			cout<<"00";
			return 0;
		}
		if(s1[2]=='D'&&s2[2]=='F'||s1[2]=='F'&&s2[2]=='D'){
			cout<<'1';
		}else if((s1[2]-'A')-(s2[2]-'A')==1||(s2[2]-'A')-(s1[2]-'A')==1){
			if(s1[2]!='C'&&s2[2]!='D'||s1[2]!='D'&&s2[2]!='C'){
				cout<<'1';
			}else cout<<'0';
		}else cout<<'0';
	}
	return 0;
}
