#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	vector<char> a1(a.begin(),a.end());
	vector<char> c1(c.begin(),c.end());
	for(int i=0;i<2;i++){
		if(a1[i]!=c1[i]){
			cout<<0000;
			return 0;
		}
	}
	cout<<1;
	vector<char> b1(b.begin(),b.end());
	vector<char> d1(d.begin(),d.end());
	for(int i=0;i<2;i++){
		if(a1[i]!=c1[i]){
			cout<<000;
			return 0;
		}
	}
	cout<<1;
	if((b1[2]>'C'&&d1[2]<'D')||(b1[2]<'D'&&d1[2]>'C')){
		cout<<00;
		return 0;
	}
	cout<<1;
	if(b1[2]-d1[2]==1||d1[2]-b1[2]==1){
		cout<<1;
	}
	return 0;
}
