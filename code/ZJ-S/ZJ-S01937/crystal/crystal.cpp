#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
#define int long long
inline int read(){
	int x=0,f=1;char c=getchar();
	while(!isdigit(c)){
		if(c=='-')f=-f;
		c=getchar();
	}
	while(isdigit(c)){
		x=x*10+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	int ans=0;
	int l=1,v=a[1],vl=a[1],sum=0;
	for(int r=1;r<=n;r++){
		v=a[r];
		sum=sum+(r-l)*(v-vl);
		while(sum>m){
			sum=sum-(a[r]-a[l]);
			l++;
		}
		ans=max(ans,r-l+1);
		vl=v;
	}
	printf("%d\n",ans);
	return 0;
}

//14:47 美美写完第一题