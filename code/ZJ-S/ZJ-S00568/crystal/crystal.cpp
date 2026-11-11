#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+ch-'0',ch=getchar();
	return f*x;
}
long long n,m,a[500005];
bool f=true;
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+n+1);
	int dx=a[2]-a[1];
	for(int i=3;i<=n;i++)if(a[i]-a[i-1]!=dx){f=false;break;}
	if(f){
		long long sum=0,s=0;
		for(int i=1;i<=n;i++){
			sum+=dx;
			if(s+sum<=m)s+=sum;
			else{cout<<i;return 0;}
		}
		cout<<n;
	}
	int ans=1;
	for(int i=1;i<=n;i++){
		long long sum=0;
		for(int j=i-1;j>=1;j--){
			if(sum+(a[i]-a[j])<=m)sum+=a[i]-a[j],ans=max(ans,i-j+1);
		}
	}
	cout<<ans;
	return 0;
}
