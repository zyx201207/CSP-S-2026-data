#include<bits/stdc++.h>
using namespace std;
int a[500005];
long long ans[300005];
bool vis[300005];
int st[500005];
int st_tail=0;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    int n,m;scanf("%d%d",&n,&m);
    int flag=1;
    for(int i=1;i<=n;++i){
    	scanf("%d",a+i);
    	if(a[i]<a[i-1])flag=0;
	}
	if(flag){
		for(int i=1;i<=n+1;++i){
			if(a[i]!=a[i-1])ans[a[i-1]]+=i-1;
		}
	}
	else if(m==2){
		for(int i=1;i<=n;++i){
			if(a[i]!=a[n])++ans[a[i]];
		}ans[a[n]]=n;
	}else{
	    for(int s=1;s<=n;++s){
	    	for(int i=s;i<=n;++i){
	    		while(vis[a[i]]&&st_tail){
	    			vis[st[st_tail--]]=0;
				}
				vis[a[i]]=1;
	    		st[++st_tail]=a[i];
			}
			while(st_tail){
				vis[st[st_tail]]=0;
				++ans[st[st_tail]--];
				--st_tail;
			}
		}
	}
	for(int i=1;i<m;++i)printf("%lld ",ans[i]);
	printf("%lld\n",ans[m]);
    return 0;
}
