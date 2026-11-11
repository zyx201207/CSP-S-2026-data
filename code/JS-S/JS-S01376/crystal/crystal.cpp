#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,sum,c,cm,a[N];
inline int read(){
	int s=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)){s=(s<<1)+(s<<3)+(ch-'0');ch=getchar();}
	return s*f;
}
signed main(){
	ios::sync_with_stdio(false);
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	for(int i=n;i>=1;i--){
		if((sum+(a[n]-a[i]))<=m)sum+=(a[n]-a[i]),c++;
		else break;
	}
	cm=c;
	for(int i=n-1;i>=1;i--){
		while(a[i]==a[i+1])i--,c--;
		sum-=(a[i+1]-a[i])*(c-1);c--;
		for(int j=i-c;j>=1;j--){
			if((sum+(a[i]-a[j]))<=m)sum+=(a[i]-a[j]),c++;
			else break;
		}
		cm=max(c,cm);
		if(i<=cm)break;
	}
	printf("%lld",cm);
	return 0;
}
