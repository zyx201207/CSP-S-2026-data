#include<bits/stdc++.h>
using namespace std;
int n,m,tot;
int a[500005],b[300005],ls[500005];
inline int read(){
    int x=0,f=1;
    char c=getchar();
    while(c<'0'&&c>'9'){
        if(c=='-') f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=x*10+(c-'0');
        c=getchar();
    }
    return x*f;
}
int main(){
    freopen("card.in","r",stdin);
    freopen("card.out","w",stdout);
    n=read(),m=read();
    for(int i=1;i<=n;i++) a[i]=read();
    for(int i=1;i<=n;i++){
        tot=0;
        for(int j=i;j<=n;j++){
            int l=0;
            for(int h=1;h<=tot;h++){
				if(ls[h]==a[j]){
					l=1;
                    tot=h;
                    break;
				}
			}	
            if(l==0){
                tot++;
                ls[tot]=a[j];
            }
        }
        for(int j=1;j<=tot;j++) b[ls[j]]++;
    }
    for(int i=1;i<=m;i++) cout<<b[i]<<" ";
    return 0;
}
