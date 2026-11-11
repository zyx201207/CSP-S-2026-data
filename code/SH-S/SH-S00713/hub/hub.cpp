#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	char ch=getchar();
	int op=1,x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			op=-1;
		}
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return op*x;
}
const int N=1e6+9;
int C,T;
int n,k;
void solveA(){
	while(T--){
		n=read();
		k=read();
		for(int i=1;i<n;i++){
			int u=read(),v=read();
			
		}
		int ans=n;
		int m=(n-1)/2;
		if(k==n){
			cout<<0<<'\n';
			continue;
		}
		else if(k>=m){
			cout<<1<<'\n';
			continue;
		}
		int l1=1,r1=m;
		bool fg=0;
		while(r1-l1+1>=k){
			int cnt=max(l1,m+1-r1);
			cnt=max(cnt,(r1-l1+3-k)/2+1);
			ans=min(ans,cnt);
			if(fg){
				l1++;
			}
			else{
				r1--;
			}
			fg^=1;
		}
		cout<<ans<<'\n';
	}
	
}
signed main(){
	freopen("hub.in","r",stdin);
	freopen("hub.out","w",stdout);
	C=read();
	T=read();
//	if(13<=C&&C<=14){
		solveA();
//	}
	return 0;
}
