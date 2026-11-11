#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline long long read(){
	long long x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
ll n,l,ans;
char c[210000000];
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		ll a;
		char ch;
		cin>>a>>ch;
		for(int j=1;j<=a;j++){
			l++;
			c[l]=ch;
		}
	}
	for(int i=1;i<=l/2;i++){
		if(c[i]!=c[l+1-i])ans++;
	}
	cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}

