#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
long long n,m,a[N],sum[N],ans=1,l,r;
inline long long read(){
	long long ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}while(isdigit(ch)){
		ans=ans*10+ch-'0';
		ch=getchar();
	}return ans*f;
}
bool check(long long mid,long long now){
	return a[now]*(now-mid)-sum[now-1]+sum[mid-1]<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;++i){
		a[i]=read();
	}sort(a+1,a+1+n);
	for(int i=1;i<=n;++i){
		sum[i]=a[i]+sum[i-1];
	}
	for(int i=2;i<=n;++i){
		long long tmp=0;
		l=1,r=i;
		while(l<r){
			long long mid=l+(r-l>>1);
			if(check(mid,1ll*i)){
				tmp=max(tmp,i-mid+1);
				r=mid;
			}else l=mid+1;
		}ans=max(tmp,ans);
	}cout<<ans;
	return 0;
} 
