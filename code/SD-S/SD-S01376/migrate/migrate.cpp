#include<bits/stdc++.h>
using namespace std;

inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0' || ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0' && ch<='9'){
		x=x*10+ch-48;
		ch=getchar();
	}
	return x*f;
}

int c,T;
int f[505][505];
void solve(){
	int n,d;
	n=read();d=read();
	vector<int> x(n+1);
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=n;i++){
		x[i]=read();
	}
	for(int i=1;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<=n;k++){
				int delta=x[j]-x[i]+x[k]-x[j];
				if(x[j]-x[i]<=d && x[k]-x[j]<=d) f[i][k]=min(f[i][k],delta);
			}
		}
	}
	int cnt=0;
	for(int i=1;i<n-1;i++){
		int cnt1=0;
		for(int j=i+1;j<n;j++){
			int cnt2=0;
			for(int k=j+1;k<=n;k++){
				int delta=x[j]-x[i]+x[k]-x[j];
				if(f[i][k]==delta){
					cnt2++;
				}
			}
			cnt1=max(cnt1,cnt2);
		}
		cnt=max(cnt,cnt1);
	}
	printf("%d\n",cnt-1);
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read();T=read();
	while(T--){
		solve();
	}
	return 0;
}
/*
0 2

4 2

1 2 3 4

5 2

1 2 3 4 5

--------------------
0 2
5 3
-2 -1 0 1 2
6 2
-4 -3 -2 -1 3 6

9 9 7 3 6 8 4 6 4 
*/
