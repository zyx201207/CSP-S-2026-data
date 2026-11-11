#include<bits/stdc++.h>
#define int long long
#define N 2145140
#define pii std::pair<int,int>
#define elif else if
int read(){
	int s=0,f=1;char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while('0'<=c&&c<='9'){
		s=s*10+(c-'0');
		c=getchar();
	}
	return s*f;
}
const int maxn=2e7;
int x[N],n,d;

int c,_;

namespace _1{
	int f[N],fg[N],f2[N];
	void solve(){
		int ans=0;
		for(int i=1;i<=n;++i){
			for(int j=i+1,k=i;j<=n;++j){
				while(k<j&&x[k]<x[j]-d)k++; 
				if(j==k){break;}
				f[j]=f[k]+1;
				if(j-k>=3&&f[k+2]==f[k]){
					fg[j]=1;f2[j]=0;
					continue;
				}
				if(j-k>=2&&f[k+1]==f[k]&&(fg[k]||fg[k+1])){
					fg[j]=1;f2[j]=0;
					continue;	
				}
				if(f2[k]&&f[k]!=f[k+1]){
					ans++;
					f2[j]=fg[j]=1;	
				}elif(f[k]==f[k+1]&&(fg[k]==0&&fg[k+1]==0)){
					ans++;
					f2[j]=fg[j]=1;	
				}else{
					f2[j]=fg[j]=0;
				}
			}
			for(int j=i;j<=n;++j){
				f[i]=fg[i]=f2[i]=0;
			}		
		} 
		printf("%lld\n",ans);
	}
	void clear(){
		for(int i=1;i<=n;++i)x[i]=f[i]=f2[i]=fg[i]=0;
	}
	void M(){
		while(_--){
			n=read(),d=read();
			for(int i=1;i<=n;++i)x[i]=read();
			solve(); 
			clear();
		}
	}
}

namespace _2{
	void M(){
		while(_--){
			n=read(),d=read();int dl=0;
			for(int i=1;i<=n;++i){x[i]=read();}
			if(n==1){
				printf("0\n");
				continue;	
			}
			dl=x[2]-x[1];
			int ans=0;
			int len=2*(d/dl);
			if(len>n) ans=0;
			elif(d<2*dl)ans=0;
			else ans=n-(len-1);
			printf("%lld\n",ans);
		}
	}
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),_=read();
	if(c<=10){
		_1::M(); 
	}if(c==11||c==12){
		_2::M();
	}
	return 0;
}
// 40pts 17:18
// 48pts 17:36
// 没时间了 
/*
0 2	
4 2
1 2 3 4
5 2
1 2 3 4 5
*/


/*
0 1 
6 4
-3 0 1 2 3 4
*/

