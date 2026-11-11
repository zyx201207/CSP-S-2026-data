#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
int c1,c2; 
string s1,s2;
signed main(){
	freopen("travel.in","r",stdin),freopen("travel.out","w",stdout);
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		if(s1[0]==s2[0] and s1[1]==s2[1]){
			cout<<1;
			int x=s1[2]-'A'+1,y=s2[2]-'A'+1;
		if(x<=3 and y<=3 or x>=4 and y>=4){
			cout<<1;
			int n=(s1[0]-'0')*10+s1[1]-'0',m=(s2[0]-'0')*10+s2[1]-'0';
			if(abs(x-y)==1 and n==m or x==y and abs(n-m)==1){
				cout<<1;
			}else cout<<0;
		}else cout<<"00";
		}else cout<<"000";
	}
	else{cout<<"0000";return 0;}
	return 0;
} 
