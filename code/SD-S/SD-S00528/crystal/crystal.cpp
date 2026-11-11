#include<bits/stdc++.h>
using namespace std;

#define ll long long

inline ll read(){
	ll f=1,x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return f*x;
}

const int N=6e5+5;
ll n,m;
ll a[N];
ll b[N];
int ans=0;

bool check(int i,int j){
	return b[i]-b[i-j]+m>=a[i]*j;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1,less<ll>());
	for(int i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	for(int i=1;i<=n;i++){
		int l=1,r=i;
		while(l<=r){
			int mid=(l+r)>>1;
			if(check(i,mid)){
				l=mid+1;
				ans=max(ans,mid);
			}else{
				r=mid-1;
			}
		}
	}
	printf("%d\n",ans);
	return 0;
} 
