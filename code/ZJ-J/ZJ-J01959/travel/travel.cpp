#include<bits/stdc++.h>
using namespace std;
#define fast ios::sync_with_stdio(0),cin.tie(0),cout.tie(0)
#define endl "\n"
using ll=long long;
using pii=pair<int,int>;
void solve(){
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		string a1,a2;
		a1+=s1[0]+s1[1];
		a2+=s2[0]+s2[1];
		if(a1==a2){
			char b1,b2;
			b1=s1[2],b2=s2[2];
			if(b1>b2)
				swap(b1,b2);
			if((b1<='C'&&b2<='C')||(b1>='D'&&b2>='D')){
				if(b1+1==b2)
					cout<<"1111";
				else
					cout<<"1110";
			}
			else{
				cout<<"1100";
			}
		}
		else{
			cout<<"1000";
		}
	}
	else{
		cout<<"0000";
	}
	return ;
}
int main(){
	fast;
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	int T=1;
	while(T--){
		solve();
	}
	return 0;
}
