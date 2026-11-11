#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	
	ios::sync_with_stdio(false);
	cin.tie(0);
	string c1,s1,c2,s2;
	
	bool flag=false,ok=false;	
	cin>>c1>>s1>>c2>>s2;
	if(c1==c2){
		cout<<1;
		ok=true;
	}
	else cout<<0;
	string w1,w2;
	w1=s1[0]+s1[1];
	w2=s2[0]+s2[1];
	if(w2==w1 and ok){
		cout<<1;
		flag=true;
	}
	else cout<<0;//02 01A 03 01A
	if(((s1[2]<='C' and s2[2]<='C') or (s1[2]>='D' and s2[2]>='D'))and flag and ok){
		cout<<1;
	}
	else cout<<0;
	if(((s1[2]+1 == s2[2] or s1[2]-1 == s2[2]) and ((s1[2]!='C' and s2[2]!='D') and (s1[2]!='D' and s2[2]!='C'))and flag and ok) or (s1[2]=='D' and s2[2]=='F' or s1[2]=='F' and s2[2]=='D' ))cout<<1;
	else cout<<0;
	return 0;
} 

