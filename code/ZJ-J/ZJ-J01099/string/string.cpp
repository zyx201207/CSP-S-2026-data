#include<bits/stdc++.h>
#define maxn 200005
using namespace std;
int n;
long long a[maxn],ans,hed,til;
char c[maxn];
int read(){
	int f=1,r=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))r=(r<<3)+(r<<1)+(ch&15),ch=getchar();
	return f*r;
}
char gtc(){
	char ch=getchar();
	while(ch<'a'||ch>'z'||ch==' ')ch=getchar();
	return ch;
}

int main()
{
	freopen("string.in","r",stdin);//change
	freopen("string.out","w",stdout);//change
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=(long long)read();
		c[i]=gtc();
	}
	hed=1,til=n;
	while(hed<til){
		if(c[hed]!=c[til])ans+=min(a[hed],a[til]);
		if(a[hed]<a[til])a[til]-=a[hed],hed++;
		else if(a[hed]>a[til])a[hed]-=a[til],til--;
		else til--,hed++;
	}
	printf("%lld",ans);
	return 0;
}