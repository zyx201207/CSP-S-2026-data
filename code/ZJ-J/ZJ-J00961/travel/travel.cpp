#include<bits/stdc++.h>
//#define int long long
using namespace std;
inline int read(){
	int ret=0;char ch=getchar();bool sgn=0;
	while(!isdigit(ch)) sgn^=(ch=='-'),ch=getchar();
	while(isdigit(ch)) ret=ret*10+ch-'0',ch=getchar();
	return sgn?-ret:ret;
}
string s[3],c[3];
signed main(){
	freopen("travel.in","r",stdin);
	freopen("travel.out","w",stdout);
	cin>>c[1]>>s[1]>>c[2]>>s[2];
	if(c[1]!=c[2]) printf("0000");
	else{
		printf("1");
		if(s[1][0]!=s[2][0]||s[1][0]==s[2][0]&&s[1][1]!=s[2][1]){
			printf("000");
		}else{
			printf("1");
			char a=s[1][2],b=s[2][2];
//			cerr<<a<<' '<<b<<endl;
			if('A'<=a&&a<='C'&&'A'<=b&&b<='C'||'D'<=a&&a<='F'&&'D'<=b&&b<='F'){
				printf("1");
				if(abs(a-b)==1) printf("1");
				else printf("0");
			}else printf("00");
		}
	}
	return 0;
}