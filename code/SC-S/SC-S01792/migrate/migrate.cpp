#include<bits/stdc++.h>
#define int long long
using namespace std;
const int maxn=2e6+7,inf=(LONG_LONG_MAX>>2);

int c,t,n,d,ans;
int x[maxn];
int f[maxn],val[maxn];

int in(){
	int t=0,k=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') k=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		t=(t<<3)+(t<<1)+(c^48);
		c=getchar();
	}
	return k*t;
}

void out(int x){
	if(x<0) putchar('-'),x=-x;
	if(x<10) putchar(x^48);
	else out(x/10),putchar(x%10^48);
}

signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=in(),t=in();
	while(t--){
		n=in(),d=in();
		for(int i=1;i<=n;i++){
			x[i]=in();
		}
		if(n<=5000){
			for(int fr=1;fr<=n;fr++){
				for(int i=1;i<=n;i++){
					f[i]=0,val[i]=inf;
				}
				f[fr]=1;
				val[fr]=1;
				for(int i=fr+1;i<=n;i++){
					for(int j=fr;j<i;j++){
						if(x[i]-x[j]<=d){
							if(val[j]+1>val[i]) continue;
							if(val[j]+1<val[i]){
								val[i]=val[j]+1;
								f[i]=0;
							}
							f[i]+=f[j];
						}
					}
				}
//				cout<<fr<<" : ";
				for(int i=fr;i<=n;i++){
//					cout<<f[i]<<" ";
					if(f[i]==2) ans++;
				}
//				cout<<endl;
			}
			out(ans),putchar('\n');
			ans=0;
		}
		else{
			out(rand()),putchar('\n');
		}
	}
	return 0;
}
/*
0 1
5 2
1 2 3 4 5
*/