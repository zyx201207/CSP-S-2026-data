#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll rd(){
	char ch=getchar();bool f=1;ll ret=0;
	while(ch>'9'||ch<'0') f|=(ch=='-'),ch=getchar();
	while(ch<='9'&&ch>='0') ret*=10,ret+=ch-'0',ch=getchar();
	return f?-ret:ret;
}
int main(){
	return 0;
}
