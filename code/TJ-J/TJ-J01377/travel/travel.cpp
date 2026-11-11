#include <bits/stdc++.h>
using namespace std;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2) cout<<1;
	else{
		cout<<"0000";
		return 0;
	}
	int len1=static_cast<int>(s1.size());
	int len2=static_cast<int>(s2.size());
	string ss1,ss2;
	char cc1,cc2;
	for(int i=0;i<len1;i++) {
		if(isdigit(s1[i])) ss1+=s1[i];
		else cc1=s1[i];
	}
	for(int i=0;i<len2;i++) {
		if(isdigit(s2[i])) ss2+=s2[i];
		else cc2=s2[i];
	}
//	cout<<cc1<<cc2;
	if(ss1==ss2) cout<<1;
	
	else{
		cout<<"000";
		return 0;
	}
	if((cc1=='D'&&cc2=='F')||(cc2=='D'&&cc1=='F')||(cc1<='C'&&cc2<='C')) cout<<1;
	else {
		cout<<"00";
		return 0;
	}
	if(cc1+1==cc2||cc1-1==cc2) cout<<1;
	else cout<<0;
	return 0;
}
