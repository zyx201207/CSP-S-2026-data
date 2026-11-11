#include<bits/stdc++.h>
using namespace std;
#define file(s) freopen(#s".in","r",stdin);freopen(#s".out","w",stdout)
//#define int ll
#define ll long long
#define rad read<int>
#define gc getchar
template<typename T>T read(){
	T ret=0;bool f=0;char ch;
	for(;!isdigit(ch=gc());f=!f?(ch=='-'):f);
	for(;isdigit(ch);ch=gc())ret=(ret<<3)+(ret<<1)+(ch^48);
	return f?-ret:ret;
}
bool ans1,ans2,ans3,ans4;
char c1[3],s1[3],c2[3],s2[3];
#define check(a,b,c,d) (a==c&&b==d)
signed main(){
	file(travel);
	scanf("%s%s%s%s",c1+1,s1+1,c2+1,s2+1);
	ans1=check(c1[1],c1[2],c2[1],c2[2]);
	ans2=ans1&&check(s1[1],s1[2],s2[1],s2[2]);
	ans3=ans2&&((s1[3]<='C'&&s2[3]<='C')||(s1[3]>='D'&&s2[3]>='D'));
	ans4=ans3&&(abs((int)s1[3]-s2[3])==1);
	printf("%d%d%d%d",ans1,ans2,ans3,ans4);
	return 0;
}
