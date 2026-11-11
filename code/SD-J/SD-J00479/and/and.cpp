#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
using namespace std;
const int N=2e5+10;
int read(){
	int x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+(ch^48);
		ch=getchar();
	}
	return x;
}
int n,m,a[N],tot=1,maxx,pre[N],suf[N],_2[(1<<20)+10],cnt[N];
struct Trie{
	int nxt[N<<5][2],end[N<<5],sz[N<<5];
	void insert(int x){
		int p=1;
		for(int i=30;i>=0;--i){
			int j=(x>>i)&1;
			if(!nxt[p][j]){
				nxt[p][j]=++tot;
			}
			p=nxt[p][j];
		}
		++end[p];
		return;
	}
	void dfs(int root){
		if(nxt[root][0]){
			dfs(nxt[root][0]);
		}
		if(nxt[root][1]){
			dfs(nxt[root][1]);
		}
		sz[root]=sz[nxt[root][0]]+sz[nxt[root][1]]+end[root];
		return ;
	}
	int ask(int x){
		int p=1,res=0;
		for(int i=30;i>=0;--i){
			int j=(x>>i)&1;
			if(sz[nxt[p][j]]>=m){
				res<<=1;
				res=res+j;
				p=nxt[p][j];
			}
			else{
				return res;
			}
		}
		return res;
	}
}T;
bool flg=true;
bool cmp(int a,int b){
	return a>b;
}
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	n=read();
	m=read();
	for(int i=2;i<=(1<<20);++i){
		_2[i]=_2[i>>1]+1;
	}
	for(int i=1;i<=n;++i){
		a[i]=read();
		maxx=max(maxx,a[i]);
		if((1<<_2[a[i]+1])!=a[i]+1){
			flg=false;
		}
		T.insert(a[i]);
	}
	if(n<=20){
		maxx=0;
		for(int i=0;i<(1<<n);++i){
			if(__builtin_popcount((unsigned)i)==m){
				int res=-1;
				for(int j=0;j<n;++j){
					if((i>>j)&1){
						if(res==-1){
							res=a[j+1];
						}
						else{
							res&=a[j+1];
						}
					}
				}
				maxx=max(maxx,res);
			}
		}
		printf("%d",maxx);
		return 0;
	}
	else if(m==1){
		maxx=0;
		for(int i=1;i<=n;++i){
			maxx=max(maxx,a[i]);
		}
		printf("%d",maxx);
		return 0;
	}
	else if(m==2){
		int maxx=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1;j<=n;++j){
				maxx=max(maxx,a[i]&a[j]);
			}
		}
		printf("%d",maxx);
		return 0;
	}
	else if(m==n){
		int res=0;
		for(int i=2;i<=n;++i){
			res=res&a[i];
		}
		printf("%d",res);
		return 0;
	}
	else if(m==n-1){
		pre[1]=a[1];
		for(int i=2;i<=n;++i){
			pre[i]=pre[i-1]&a[i];
		}
		suf[n]=a[n];
		for(int i=n-1;i>=1;--i){
			suf[i]=suf[i+1]&a[i];
		}
		int maxx=max(suf[2],pre[n-1]);
		for(int i=2;i<n;++i){
			maxx=max(maxx,suf[i+1]&pre[i-1]);
		}
		printf("%d",maxx);
		return 0;
	}
	else if(flg){
		sort(a+1,a+1+n,cmp);
		printf("%d",a[m]);
	}
	else if(maxx<4){
		int cnt0=0,cnt1=0,cnt2=0,cnt3=0;
		for(int i=1;i<=n;++i){
			if(a[i]==3){
				++cnt3;
			}
			if(a[i]==2){
				++cnt2;
			}
			if(a[i]==1){
				++cnt1;
			}
			if(a[i]==0){
				++cnt0;
			}
		}
		if(cnt3>=m){
			printf("3");
		}
		else if(cnt3+cnt2>=m){
			printf("2");
		}
		else if(cnt3+cnt1>=m){
			printf("1");
		}
		else{
			printf("0");
		}
		return 0;
	}
	T.dfs(1);
	for(int i=1;i<=n;++i){
		maxx=max(maxx,T.ask(a[i]));
	}
	printf("%d",maxx);
	return 0;
}
/*
4 2
3 15 12 12
*/
