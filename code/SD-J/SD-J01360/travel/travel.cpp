#include<bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a1,b1;
string a2,b2;
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout); 
	cin>>a1>>a2>>b1>>b2;
	if(a1==b1) cout<<1;
	else cout<<0;
	int x=a2[0]-'0'+a2[1]-'0';
	int y=b2[0]-'0'+b2[1]-'0';
	if(x==y && a1==b1) cout<<1;
	else cout<<0;
	bool p=a2[2]<='C';
	bool q=b2[2]<='C';
	if(p==q && x==y && a1==b1) cout<<1;
	else cout<<0;
	if((a2[2]+1==b2[2] || a2[2]-1==b2[2]) && p==q && x==y && a1==b1) cout<<1;
	else cout<<0;
	return 0;
}
