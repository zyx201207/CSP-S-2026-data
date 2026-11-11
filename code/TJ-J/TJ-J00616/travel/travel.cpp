#include<bits/stdc++.h>
using namespace std;
int main(){
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1!=c2) cout<<"0000";
	else{
		cout<<1;
		string p1=s1.substr(0,2),p2=s2.substr(0,2);
		if(p1!=p2) cout<<"000";
		else{
			cout<<1;
			char l1=s1[2],l2=s2[2];
			if(l1<='C'&&l2<='C'||l1>'C'&&l2>'C'){
				cout<<1;
				int d=abs((l1-'A')-(l2-'A'));
				if(d==1) cout<<1;
				else cout<<0;
			}
			else cout<<"00";
		}
	}
	return 0;
}
