#include<bits/stdc++.h>
using namespace std;
#define int long long
#define gc_ getchar()
inline int read(){
	int x=0,f=1;char ch=gc_;
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=gc_;}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=gc_;}
	return x*f;
}
int c,T,n,d,a[2000005],sum=0,b[2000005];
//map<int,map<int,int> > Map;
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	c=read(),T=read();
	while(T--){
		n=read(),d=read();sum=0;
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		for(int i=1;i<=n;i++){
			int ps1=upper_bound(a+1,a+1+n,a[i]+d)-a-1;
			int ps2=upper_bound(a+1,a+1+n,a[ps1]+d)-a-1;
//			cout<<i<<" "<<ps1<<" "<<ps2<<endl;
			for(int j=ps2;j>=i+3;j--){
				int cnt=0;
				for(int k=j;k>=i;k--){
					if(a[j]-a[k]<=d&&a[k]-a[i]<=d)cnt++;
					if(cnt>2)break;
				}
//				cout<<" "<<j<<" "<<cnt<<endl;
				if(cnt==2){
					int l=i-1;
					while(l>=1&&a[l+2]-a[l]>d&&a[l+1]-a[l]<=d)l--;
					int r=j+1;
					while(r<=n&&a[r]-a[r-2]>d&&a[r]-a[r-1]<=d)r++;
					sum+=(i-l)*(r-j);
				}
			}
		}
		cout<<sum<<endl;;
	}
	return 0;
} 
/*
我-作为一名绝望的oier，已经没有什么事情可以让我睁眼了；
q-第三题有思路； 
我-哦？；
q-（一小时后）错解；
我-哦。 
*/
