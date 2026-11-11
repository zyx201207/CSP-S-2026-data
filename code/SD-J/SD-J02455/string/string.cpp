#include<bits/stdc++.h>
using namespace std;
const int I=200010;
struct node{
	int a;
	char c;
	long long s;
}x[I];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	int n;
	long long ans=1,cnt=0;
	scanf("%d",&n);
	string s="";
	for(int i=1;i<=n;i++){
		scanf("%d %c",&x[i].a,&x[i].c);
		for(int j=1;j<=x[i].a;j++)s+=x[i].c;
		ans+=x[i].a;
	}
	ans-=1;
	for(int i=1;i<=ans/2;i++){
		if(s[i-1]!=s[ans-i])cnt++;
	}
	printf("%lld",cnt);
	return 0;
}/*
6
2 a
2 b
1 c
1 a
1 d
2 a
*/
