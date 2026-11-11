#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e5+5;
int n,m,a[N],q[N],ans;
int read(){
	int f=1,sum=0;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		sum=sum*10+ch-'0';
		ch=getchar();
	}
	return f*sum;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		a[i]+=1e12+1;
	}
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++){
		q[i]=q[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int sum=a[i]*i;
		if(q[i]+m>=sum){
			ans=i;
			continue;
		}
		int l=1,r=i,p=i;
		while(l<=r){
			int mid=(l+r)/2;
			if(q[i]-q[mid-1]+m>=a[i]*(i-mid+1)){
				p=mid;
				r=mid-1;
			}
			else{
				l=mid+1;
			}
		}
		ans=max(ans,i-p+1);
	}
	cout<<ans<<endl;
	return 0;
}
