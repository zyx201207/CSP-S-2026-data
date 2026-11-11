#include<bits/stdc++.h>
using namespace std;
long long n,m,a[500001],mx,mi,sum[500001],ans=-1;
inline long long read(){
	long long res=0;
	int flag=1;
	char ch=getchar();
	while((ch<'0'||ch>'9')&&ch!='-')ch=getchar();
	if(ch=='-'){
		flag=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		res=res*10+ch-'0';
		ch=getchar();
	}
	if(flag==-1)return -res;
	return res;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1]+a[i];
	}
	if(n<=5000){
		for(int i=1;i<=n;i++){
			for(int j=i;j<=n;j++){
				if(a[j]*(j-i+1)-sum[j]+sum[i-1]<=m){
					long long x=j-i+1;
					ans=max(ans,x);
				}
			}
		}
	}else{
		int gongcha=a[2]-a[1];
		int l=1,r=n;
		while(l<=r){
			long long mid=l+(r-l)/2;
			if((mid+1)*mid/2<m){
				l=mid+1;
			}else if((mid+1)*mid/2>m){
				r=mid-1;
			}else{
				ans=mid;
				break;
			}
		}
		ans=l;
	}
	cout<<ans;
	return 0;
}
