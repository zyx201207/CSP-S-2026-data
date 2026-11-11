#include<bits/stdc++.h>
#define LL long long int
using namespace std;
char C[3],S[4],c[3],s[4];
int main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>C+1>>S+1>>c+1>>s+1;
	int X=C[1]*10+C[2],x=c[1]*10+c[2];
	if(X!=x){
		cout<<"0000";
		return 0;
	}
	int P=S[1]*10+S[2],p=s[1]*10+s[2];
	if(P!=p){
		cout<<"1000";
		return 0;
	}
	if(!(('A'<=S[3]&&s[3]<='C'&&'A'<=s[3]&&s[3]<='C')||('D'<=S[3]&&s[3]<='F'&&'D'<=s[3]&&s[3]<='F'))){
		cout<<"1100";
		return 0;
	}
	if(S[3]+1!=s[3]&&S[3]-1!=s[3]){
		cout<<"1110";
		return 0;
	} else {
		cout<<"1111";
	}
	return 0;
}