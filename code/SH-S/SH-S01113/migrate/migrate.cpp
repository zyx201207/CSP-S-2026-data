#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
inline ll read(){
	char ch=getchar();
	ll x=0,f=1;
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
inline void write(ll x){
	if(x<0)x=-x,putchar('-');
	if(x>9)write(x/10);
	putchar(x%10+48);
}
const int N=2e3+10;
ll c,t;
ll x[N],f[N][N];
int main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	cin>>c>>t;
	while(t--){
		int n=read(),t=read(),flag=0,cnt=0;
		memset(f,0,sizeof f);
		for(int i=1;i<=n;i++){
			x[i]=read();
		}
		for(int i=1;i<n;i++){
			if(x[i+1]-x[i]<=t)f[i][i+1]=1;
		}
		for(int len=1;len<n;len++){
			for(int j=1;j<=n-len;j++){
				for(int k=1;k<len;k++){
					if(x[k+j]-x[j]<=t&&x[len+j]-x[k+j]<=t)
						f[j][j+len]+=f[j][k+j]*f[k+j][len+j];
				}
			}
		}
		for(int i=1;i<=n;i++){
			for(int j=1;j<=n;j++){
//				cout<<f[i][j]<<" ";
				if(f[i][j]==2)cnt++;
			}
//			cout<<endl;
		}
		cout<<cnt<<endl;
	}
	return 0;
}
