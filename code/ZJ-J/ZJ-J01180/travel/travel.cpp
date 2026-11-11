#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
string c1,s1,c2,s2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>c1>>s1>>c2>>s2;
	ll a=s1[2],b=s2[2];
	if(c1!=c2){
		cout<<"0000\n";
		return 0;
	}
	else if(s1[0]!=s2[0]||s1[1]!=s2[1]){
		cout<<"1000\n";
		return 0;
	}
	else if((s1[2]>='D'&&s1[2]<='C')||(s1[2]<='C'&&s2[2]>='D')){
		cout<<"1100\n";
		return 0;
	}
	else if(abs(a-b)!=1){
		cout<<"1110\n";
		return 0;
	}
	else cout<<"1111\n";
}