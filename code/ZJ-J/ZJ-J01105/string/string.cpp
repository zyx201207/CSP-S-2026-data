#include<bits/stdc++.h>
using namespace std;
const int maxn=200005;
int n,a[maxn],ans;
char c[maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){int ret=0,f=1;ch=getchar();}
	while( isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
int main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read(),scanf("%c",&c[i]);
	}
	int l=1,r=n;
	while(l!=r){
		if(a[l]==a[r]){
			if(c[l]!=c[r])ans+=a[l],l++,r--;else l++,r--;
			continue;
		}
		if(a[l]>a[r]){
			a[l]-=a[r];
			if(c[l]!=c[r])ans+=a[r],r--;else r--;
			continue;
		}
		if(a[r]>a[l]){
			a[r]-=a[l];
			if(c[r]!=c[l])ans+=a[l],l++;else l++;
			continue;
		}
	}
	printf("%d\n",ans);
	return 0;
}
