#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=2e6+5;
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
void print(int x){
	if(x<10){
		putchar('0'+x);
		return ;
	}
	print(x/10);
	putchar(x%10+'0');
}
int C,T,n,d,a[N],ans;
int nxt[N],pre[N];
int st[N],idx;
bool check(int s,int e){
	idx=0;
	int x=s,y=e,sum=1;
	while(nxt[x]<e){
		if(nxt[x]==x) return false;
		st[++idx]=nxt[x];
		x=nxt[x];
	}
	for(int i=idx;i>=1;i--){
		sum*=abs(st[i]-pre[y]+1);
		y=pre[y];
		if(sum>2) return false;
	}
	return sum==2;
}
signed main(){
	freopen("migrate.in","r",stdin);
	freopen("migrate.out","w",stdout);
	C=read(),T=read();
	while(T--){
		ans=0;
		n=read(),d=read();
		for(int i=1;i<=n;i++){
			a[i]=read();
		}
		for(int i=1;i<=n;i++){
			int l=i,r=n,p=i;
			while(l<=r){
				int mid=(l+r)/2;
				if(a[mid]-a[i]<=d){
					l=mid+1;
					p=mid;
				}
				else{
					r=mid-1;
				}
			}
			nxt[i]=p;
		}
		for(int i=n;i>=1;i--){
			int l=1,r=i,p=i;
			while(l<=r){
				int mid=(l+r)/2;
				if(a[i]-a[mid]<=d){
					p=mid;
					r=mid-1;
				}
				else{
					l=mid+1;
				}
			}
			pre[i]=p;
		}
		for(int i=1;i<=n;i++){
			for(int j=i+2;j<=n;j++){
				if(check(i,j)){
					ans++;
				}
			}
		}
		print(ans);
		putchar('\n');
	}
	return 0;
}
