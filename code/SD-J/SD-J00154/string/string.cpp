#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 3e5+5;
int n,a[N],sum[N],len;
char c[N];
int read(){
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
	freopen("string.in","r",stdin);
	freopen("string.out","w",stdout);
	n=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		cin>>c[i];
		sum[i]=sum[i-1]+a[i];
	}
	int len=sum[n];
	int l=1,r=n,ans=0;
	while(l<r){
		int o=0;
		if(sum[l]>len/2){
			a[l]-=(sum[l]-len/2);
			if(len%2==1)a[l]--;
		}
		while(1){
			if(o+a[r]>=a[l]){
				a[r]-=(a[l]-o);
				if(c[r]!=c[l]){
					ans+=(a[l]-o);
				}
				if(a[r]==0)
				r--;
				break;
			}else{
				o+=a[r];
				if(c[r]!=c[l]){
					ans+=a[r];
				}
				r--;
			}
		}
		l++;
	}
	cout<<ans<<'\n';
	return 0;
}
