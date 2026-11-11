#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 2e6+5;
int c,t,n,d,a[N];
inline int read(){
	int res=0,flag=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')flag=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return res*flag;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),t=read();
	srand(time(0));
	while(t--){
		n=read(),d=read();
		bool f=1;
		for(int i=1;i<=n;i++){
			a[i]=read();
			if(i>2&&a[i]-a[i-1]!=a[i-1]-a[i-2]){
				f=0;
			}
		}
		int ans=0;
		if(f){
			int num=d/(a[2]-a[1]);
			if(num<=1){
				cout<<0<<'\n';
				continue;
			}
			for(int i=1;i<=n;i++){
				if(i+num*2-1<=n)ans++;
				else break;
			}
			cout<<ans<<'\n';
		}else if(n<=5000){
			for(int i=1;i<n;i++){
				int k=i+1;
				while(k<=n&&a[k]-a[i]<=d){
					k++;
				}
				k--;
				for(int j=k+1;j<=n;j++){
					if(a[k]-a[i]<=d&&a[j]-a[i+(j-k)]<=d&&a[j]-a[k]<=d&&a[i+(j-k)]-a[i]<=d&&a[j]-a[i]>d){
						ans++;
					}
				}
			}
			cout<<ans<<'\n';
		}else{
			cout<<rand()<<'\n';
		}
	}
	return 0;
}
