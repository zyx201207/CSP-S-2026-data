#include<bits/stdc++.h>
using namespace std;
string a,b,c,d;
int cnt1=1,cnt2=1,cnt3=1,cnt4=1;
int main(){
//	freopen("travel.in","r",stdin);
//	freopen("travel.out","w",stdout);
	cin>>a>>b>>c>>d;
	if(a!=c){
		cnt1=0;
		cnt2=0;
		cnt3=0;
		cnt4=0;
	}
	if(cnt1==1){
		string s,s2;
		s+=b[0];
		s+=b[1];
		s2+=d[0];
		s2+=d[1];
		if(s!=s2){
			cnt2=0;
			cnt3=0;
			cnt4=0;
		} 
	}
	if(cnt2==1){
		if((b[b.size()-1]>'C'&&d[d.size()-1]<='C')||(b[b.size()-1]<='C'&&d[d.size()-1]>'C')){
			cnt3=0;
			cnt4=0;
		}
	}
	if(cnt3==1){
		int t;
		t=abs(b[b.size()-1]-d[d.size()-1]);
		if(t!=1){
			cnt4=0;
		}
	}
	cout<<cnt1<<cnt2<<cnt3<<cnt4;
	return 0;
} 
