#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#define ll long long
using namespace std;
const ll N=2e5+10;
ll n,f,cnt,ans;
char c;
string s,t;
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%d %c",&f,&c);
		for(int j=1;j<=f;j++)s[cnt++]=c;
	}
	for(int i=cnt-1;i>=0;i--) t[cnt-i-1]=s[i];
	for(int i=0;i<cnt/2;i++){
		if(t[i]!=s[i]) ans++;
	}
	printf("%d",ans);
	return 0;
}
