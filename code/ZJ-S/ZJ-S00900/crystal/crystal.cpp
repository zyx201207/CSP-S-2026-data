#include<bits/stdc++.h>
#define LL long long 
using namespace std;
const int maxa=500005;
LL n,m,a[maxa],ans,d,sum,flg,ss;
LL read(){
	LL ret=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-') f=-f;ch=getchar();}
	while(isdigit(ch)) ret=(ret<<3)+(ret<<1)+(ch&15),ch=getchar();
	return ret*f;
} 
bool check(int x){
	return x*(2*a[1]+(x-1)*d)/2<=m;
}
bool c(int x){
	int res=0;
	for(int i=1;i<=n;i++)
	 if(a[i]>x) break;else res+=(x-a[i]);
	return res<=m;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++) a[i]=read();
	sort(a+1,a+1+n);
	d=a[2]-a[1];
	for(int i=2;i<=n;i++) if(a[i+1]-a[i]!=d) flg=1;
	if(!flg){
		int L=1,R=n;
		while(L<=R){
			LL mid=L+R>>1;
			if(check(mid)) L=mid+1;
			else R=mid-1;
		}
		printf("%lld\n",L);
		return 0;
	}
	if(n<=10000){
		for(int i=1;i<=n;i++){
			LL xx=m,sum=0,j=i;
			while(a[j]==a[i]) j++,sum++; 
			for(int j=i-1;j;j--) if(xx>=(a[i]-a[j])) xx-=(a[i]-a[j]),sum++;
			ans=max(ans,sum);
		}
		printf("%lld\n",ans);		
	}else{
		int L=a[1],R=a[n];
		while(L<=R){
			int mid=L+R>>1;
			if(c(mid)) ss=mid,L=mid+1;
			else R=mid-1;
		}
		for(int i=1;i<=n;i++) if(a[i]>ss) break;else m-=(ss-a[i]),ans++;
		printf("%lld\n",ans);
	}
	return 0;
}
/*
5 5
1 2 4 8 9
*/
