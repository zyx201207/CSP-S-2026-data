#include<bits/stdc++.h>
using namespace std;
const int N=1000010;
long long n,m,a[N],sum,b[N],lst,ans;
long long read(){
	long long x=0;
	int f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=x*10+(ch-'0');
		ch=getchar();
	}
	return x*f;
}
void write(long long x){
	if(x<0){
		putchar('-');
		x=-x;
	}
	if(x>9){
		write(x/10);
	}
	putchar(x%10+'0');
}
int two(int l,int r,int x){
	int mid,res=r;
	while(l<=r){
		mid=(l+r)/2;
		if(m>=(long long)(b[x]-b[mid]-(a[x]-a[mid])*mid)){
			res=mid;
			r=mid-1;
		}else{
			l=mid+1;
		}
	}
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
	lst=a[1];
	for(int i=2;i<=n;i++){
		if(a[i]==lst){
			b[i]=b[i-1];
		}else{
			b[i]=b[i-1]+(a[i]-a[i-1])*(i-1);
		}
	}
	for(int i=1;i<=n;i++){
		if(b[i]<=m){
			ans=i;
		    continue;
		}
	    int res=two(1,i,i);
	    if(res>ans){
	        ans=res;
	    }
	}
	write(ans);

    return 0;
}
