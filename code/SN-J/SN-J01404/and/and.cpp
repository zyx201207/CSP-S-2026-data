#include<bits/stdc++.h>
using namespace std;
inline long long read(){
	long long ans=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		ans=ans*10+ch-'0';
		ch=getchar();
	}
	return f*ans;
}
const int N=2e5+10;
int a[N],c[N];
int main(){
	freopen("and.in","r",stdin);
	freopen("and.out","w",stdout);
	bool b=0;
	long long n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]>4){
			b=1;
		}
	}
	if(b==0){
		for(int i=1;i<=n;i++){
			c[a[i]]++;
		}
		if(c[3]>m){
			cout<<3;
			return 0;
		}
		else if(c[2]>m){
			cout<<2;
			return 0;
		}
		else if(c[1]+c[2]>m){
			cout<<1;
			return 0; 
		}
		else{
			cout<<0;
			return 0;
		}
	}
	else if(m==n){
		int ans=a[1];
		for(int i=1;i<=n;i++){
			ans&=a[i];
		}
		cout<<ans;
		return 0;
	}
	else if(m==1){
		int maxn=-1;
		for(int i=1;i<=n;i++){
			maxn=max(maxn,a[i]);
		}
		cout<<maxn;
		return 0;
	}
	else if(m==2){
		long long maxn=-1;
		for(int i=1;i<=n;i++){
			for(int j=i+1;j<=n;j++){
				long long q=a[i]&a[j];
				maxn=max(maxn,q);
			}
		}
		cout<<maxn;
		return 0; 
	} 
	else if(m==n-1){
		long long maxn=-1;
		for(int i=1;i<=n;i++){
			long long ans=a[i+1];
			for(int j=1;j<=n;j++){
				if(j!=i){
					ans&=a[i];
				}
			}
			maxn=max(maxn,ans);
		}
		cout<<maxn;
		return 0;
	}
	return 0;
}
