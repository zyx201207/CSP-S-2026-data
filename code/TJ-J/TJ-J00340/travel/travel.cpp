#include <bits/stdc++.h>
using namespace std;
int main() {
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	string c1,s1,c2,s2;
	cin>>c1>>s1>>c2>>s2;
	string cnt = "",cnt1 = "",cnt2 = "",cnt3 = "";
	if(c1==c2 and c1!="01" and c1!="16" and c2!="01" and c2!="16") cout<<1;
	else {
		cout<<0<<0<<0<<0;
		return 0;
	}
	for(int i = 0; i<s1.size(); i++) {
		if(isdigit(s1[i])) cnt+=s1[i];
		else cnt1+=s1[i];
	}
	for(int i = 0; i<s2.size(); i++) {
		if(isdigit(s2[i])) cnt2+=s2[i];
		else cnt3+=s2[i];
	}
	if(cnt==cnt2) cout<<1;
	else {
		cout<<0<<0<<0;
		return 0;
	}
	if(cnt1=="A" and cnt3=="D") cout<<0<<0;
	if(cnt1=="A" and cnt3=="F") cout<<0<<0;
	if(cnt1=="D" and cnt3=="A") cout<<0<<0;
	if(cnt1=="F" and cnt3=="A") cout<<0<<0;

	if(cnt1=="B" and cnt3=="D") cout<<0<<0;
	if(cnt1=="B" and cnt3=="F") cout<<0<<0;
	if(cnt1=="D" and cnt3=="B") cout<<0<<0;
	if(cnt1=="F" and cnt3=="B") cout<<0<<0;

	if(cnt1=="C" and cnt3=="D") cout<<0<<0;
	if(cnt1=="C" and cnt3=="F") cout<<0<<0;
	if(cnt1=="D" and cnt3=="C") cout<<0<<0;
	if(cnt1=="F" and cnt3=="C") cout<<0<<0;

	if(cnt1=="A" and cnt3=="C") cout<<1<<0;
	if(cnt1=="C" and cnt3=="A") cout<<1<<0;
	
	if(cnt1=="B" and cnt3=="A") cout<<1<<1;
	if(cnt1=="A" and cnt3=="B") cout<<1<<1;
	if(cnt1=="B" and cnt3=="C") cout<<1<<1;
	if(cnt1=="C" and cnt3=="B") cout<<1<<1;
	if(cnt1=="D" and cnt3=="F") cout<<1<<1;
	if(cnt1=="F" and cnt3=="D") cout<<1<<1;

}


