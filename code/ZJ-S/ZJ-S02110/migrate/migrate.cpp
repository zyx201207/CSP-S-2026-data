#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+10;
inline int read(){
	int x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
int C,T;
int n,d;
int a[N];
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read();T=read();
	while(T--){
		n=read();d=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		int c=a[2]-a[1];
		int flag=0;
		for(int i=3;i<=n;i++){
			if(a[i]-a[i-1]!=c) flag=1;
		}
		if(!flag){
			if(d<c) cout<<"0\n";
			else if(d<=c&&c<d*2) cout<<"0\n";
			else if(d>=c*2&&d<c*3) cout<<n-3<<"\n";
			else if(d>=c*3&&d<c*10) cout<<n-5<<"\n";
			else if(d>n*10) cout<<"0\n";
			else if(d%c==0)cout<<d/c+3<<"\n";
			else cout<<"0\n";
			continue;
		}
		if(a[n]-a[1]<=2*d){
			cout<<"2\n";
			continue;
		}
		int cc=0;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				if(a[j]-a[i]<=d) continue;
				if((a[j]-a[i])%d!=0&&(a[j]-a[i])<=2*d&&(j-i)==2) cc++;
			}
		}
		cout<<cc<<"\n";
	}
	return 0;
}
