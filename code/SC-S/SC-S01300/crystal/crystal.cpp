#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=5e5+5;
int n,m;
int a[maxn];
int ans=1,s[maxn];
inline int read(){
	int num=0,f=1;
	char ch;
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		num=num*10+(ch^48);
		ch=getchar();
	}
	return num*f;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		s[i]=s[i-1]+a[i];
	}
	int l=1;
	for(int r=1;r<=n;r++){
		int up=a[r]*(r-l+1)-(s[r]-s[l-1]);
		while(up>m&&l<r){
			l++;
			up=a[r]*(r-l+1)-(s[r]-s[l-1]);
		}
		if(up<=m){
			ans=max(ans,r-l+1);
		}
	}
	cout<<ans;
	return 0;
}