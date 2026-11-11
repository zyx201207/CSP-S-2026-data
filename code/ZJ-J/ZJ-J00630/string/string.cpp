#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=200005;
int n,ans;
struct ZS{
	int x;
	char ch;
}a[maxn];
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-f;ch=getchar();}
	while(isdigit(ch))ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
}
signed main(){
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i].x=read();
		cin>>a[i].ch;
	}
	for(int i=1,j=n;i<=j;){
		if(i==j)break;
		if(a[i].x==a[j].x){
			if(a[i].ch==a[j].ch){
				i++;
				j--;
			}else{
				ans+=a[i].x;
				i++;
				j--;
			}
		}else if(a[i].x<a[j].x){
			if(a[i].ch==a[j].ch){
				a[j].x-=a[i].x;
				i++;
			}else{
				ans+=a[i].x;
				a[j].x-=a[i].x;
				i++;
			}
		}else{
			if(a[i].ch==a[j].ch){
				a[i].x-=a[j].x;
				j--;
			}else{
				ans+=a[j].x;
				a[i].x-=a[j].x;
				j--;
			}
		}
	}
	printf("%lld\n",ans);
	return 0;
}
