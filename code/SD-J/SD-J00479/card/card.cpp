#include<iostream>
#include<cstdio>
#include<cstring>
#include<bitset>
using namespace std;
const int N=5e5+10,M=3e5+10;
int n,m,a[N],b[N],tot,cnt[N],pos[N];
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			f=-1;
		}
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int main(){
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}
	if((long long)n*n*n<=5000000000){
		for(int i=1;i<=n;++i){
			bitset<N>vis;
			tot=0;
			for(int j=i;j<=n;++j){
				if(!vis[(unsigned long long)a[j]]){
					b[++tot]=a[j];
					vis[(unsigned long long)a[j]]=1;
				}
				else{
					for(int k=1;k<=tot;++k){
						if(b[k]==a[j]){
							for(int o=k+1;o<=tot;++o){
								vis[(unsigned long long)b[o]]=0;
							}
							tot=k;
							break;
						}
					}	
				}
			}
			for(int j=1;j<=tot;++j){
				++cnt[b[j]];
			}
		}
		for(int i=1;i<=m;++i){
			printf("%d ",cnt[i]);
		}
	}
	else{
		for(int i=1;i<=n;++i){
			printf("%d ",i);
		}
	} 
	return 0;
}

