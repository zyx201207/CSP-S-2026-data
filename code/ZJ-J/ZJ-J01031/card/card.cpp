#include<bits/stdc++.h>
using namespace std;
int read(){
	int ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-1;ch=getchar();}
	while(isdigit(ch)){ret=ret*10+(ch-'0');ch=getchar();}
	return ret;
}
int n,m,s[300005],a[500005],f[500005],ans[300005],len;
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    	for(int i=1;i<=n;i++){len=0;memset(s,0,sizeof s);
    		for(int j=i;j<=n;j++){
    			if(s[a[j]]==0) s[a[j]]=1,f[++len]=a[j];
            	else{
         		    while(1){
             			if(f[len]!=a[j]) s[f[len]]=0,len--;
    	        		else break;
	        		}
	         	}
	        }
			for(int j=1;j<=m;j++) ans[j]+=s[j];
		}
	for(int i=1;i<=m;i++) printf("%d ",ans[i]);
	return 0;
}
