#include<bits/stdc++.h>
using namespace std;
#define maxn 500005
#define int long long
int n,m,a[maxn],s[maxn],ans;
int read(){
	int f=1,ret=0;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-'){f=-1;}ch=getchar();}
	while(isdigit(ch)){ret=ret*10+ch-'0';ch=getchar();}
	return ret*f;
}
bool check(int x){
	for(int i=x;i<=n;i++){
		if(a[i]*x-(s[i]-s[i-x])<=m){
			return true;
		}
	}
	return false;
}
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	for(int i=1;i<=n;i++) s[i]=s[i-1]+a[i];
	int L=1,R=n;
	while(L<=R){
		int mid=(L+R)/2;
		if(check(mid)) ans=mid,L=mid+1;
		else R=mid-1;
	}
	printf("%d",ans);
	return 0;
}
