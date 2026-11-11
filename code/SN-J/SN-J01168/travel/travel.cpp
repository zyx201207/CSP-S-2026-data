#include<bits/stdc++.h>
using namespace std;
string a1,a2,b1,b2;
bool bl=0;
map<char,int> st;
void blc(){
	if(bl) cout<<0;
	else cout<<1;
}

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	st['A']++;
	st['B']++;
	st['C']++;
	cin>>a1>>a2>>b1>>b2;
	if(a1!=b1)	bl=1;
	blc();
	if(a2[0]!=b2[0]||a2[1]!=b2[1]) bl=1;
	blc();
	if(a2[2]=='E'&&b2[2]!='F') bl=1;
	else if(a2[2]=='F'&&b2[2]!='E') bl=1;
	else if(st[a2[2]]==1&&st[b2[2]]==0) bl=1;
	blc();
	if(st[a2[2]]==1&&st[b2[2]]==1){
		if(a2[2]!='B'&&b2[2]!='B') bl=1;
	}
	blc();


	return 0;
} 
