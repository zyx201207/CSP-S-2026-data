#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=1e6+5;
int a,b;
string s,c; 
int main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>s>>b>>c;
	if(a==b){
		cout<<1;
	}else{
		cout<<"0000";
		return 0;
	}
	int l=(s[0]-'0')*10+(s[1]-'0'),r=(c[0]-'0')*10+(c[1]-'0');
	if(l==r){
		cout<<1;
	}else{
		cout<<"000";
		return 0;
	}
	if((s[2]>='A'&&s[2]<='C'&&c[2]>='A'&&c[2]<='C')||(s[2]>='D'&&s[2]<='F'&&c[2]>='D'&&c[2]<='F')){
		cout<<1;
		if(((s[2]+1)==c[2])||((c[2]+1)==s[2])){
			cout<<1;
		}else{
			cout<<0;
		}
	}else{
		cout<<"00";
	}
	return 0;
}
