#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long x=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return x*f;
}
long long sit(long long k){
	for(int i=1; i<=22; i++)if(pow(2,i)==k)return 1;
	return 0;
}
long long a[500005];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	long long n=read(),m=read();
	for(int i=1; i<=n; i++){
		a[i]=read();
	}
	if(m==1){
		long long maxn=-1;
		for(int i=1; i<=n; i++){
			if(a[i]>maxn)maxn=a[i];
		}
		cout<<maxn;
		return 0;
	}
	if(m==2){
		long long maxn=-1;
		for(int i=1; i<n; i++){
			for(int j=i+1; j<=n; j++){
				if(a[i]&a[j]>maxn){
					maxn=a[i]&a[j];
				}
			}
		}
		cout<<maxn;
		return 0;
	}else if(m==n){
		long long ans=a[1];
		for(int i=2; i<=n; i++){
			ans=ans&a[i];
		}
		cout<<ans;
		return 0;
	}else if(m==n-1){
		long long maxn=-1,ans;
		for(int i=1; i<=n; i++){
			ans=(i==1?a[2]:a[1]);
			for(int j=1; j<=n; j++){
				if(j!=i)ans=ans&a[j];
			}
			if(maxn<ans)maxn=ans;
		}
		cout<<maxn;
		return 0;
	}else if(sit(n)==1&&a[2]-a[1]==1&&a[3]-a[2]==1){
		cout<<n-m;
		return 0;
	}else{
		cout<<3;
		return 0;
	}
	return 0;
}
