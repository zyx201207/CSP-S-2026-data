#include<bits/stdc++.h>
using namespace std;
const int maxn=1000005;
int t,n,k,a[maxn],b[maxn],ans;
int read(){
	int num=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))num=num*10+ch-'0',ch=getchar();
	return num*f;
}
int main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	read(),t=read();
	while(t--){
		memset(a,0,sizeof a);
		memset(b,63,sizeof b);
		ans=1;
		n=read(),k=read();
		for(int i=1;i<n;i++){
			int x=read(),y=read();
			a[x]=max(a[x],y),b[x]=min(b[x],y);
		}
		for(int i=1;i<=n;i++){
			if(a[i] && b[i])ans=max(ans,a[i]-b[i]);
		}
		cout<<ans<<"\n";
	}
	return 0;
}