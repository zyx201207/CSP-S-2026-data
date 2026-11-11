#include<bits/stdc++.h>
#define rep(a,b,c) for(int a=b;a<=c;a++)
using namespace std;
typedef long long ll;
void fileIO(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
}
inline ll read(){
	ll s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')w=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		s=s*10+ch-'0';
		ch=getchar();
	}
	return s*w;
}
const int MAX=5e5+11;
ll n,a[MAX],m,b[MAX];
int ans;
int main(){
	fileIO();
	n=read(),m=read();
	rep(i,1,n){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	rep(i,1,n){
		b[i]=a[i]+b[i-1];
	}
	for(int l=1,r=1;r<=n;r++){
		while(a[r]*(r-l+1)-(b[r]-b[l-1])>m)l++;
		ans=max(ans,r-l+1);
	}
	printf("%d\n",ans);
	return 0;
}
