#include<bits/stdc++.h>
using namespace std;
long long n,kkk[35],m,zz;int qz[200005][35],k,anss[35],maxm[35];
struct ll{
	int d;long long s;
}a[200005];
inline long long read(){
	int c;long long anss=0;c=getchar();
	while(!isdigit(c))c=getchar();
	while(isdigit(c)){
		anss=anss*10+c-'0';c=getchar();
	}
	return anss;
}
bool chk(long long ans){
	int g=0;long long b=ans;
	for(int i=1;i<=k;i++){
		anss[i]=0;if(b%2==1)anss[i]=1;
		b=b>>1;
	}
	for(int i=1;i<zz;i++){
		++g;
		for(int j=1;j<=k;j++){
			if(qz[i][j]==0 && anss[j]==1){
				--g;break;
			}
		}
	}
	if(g>=m)return true;
	else return false;
}
bool cmp(ll x,ll y){
	return x.s>y.s;
}
int main(){
	freopen("and.in","r",stdin);//IMPORTANT
	freopen("and.out","w",stdout);
	n=read();m=read();
	kkk[0]=1;
	for(int i=1;i<=32;i++){
		kkk[i]=kkk[i-1]<<1;
	}long long b;
	for(int i=1;i<=n;i++){
		a[i].s=read();b=a[i].s;
		while(b>0){
			++a[i].d;
			if(b%2==1){
				maxm[a[i].d]++;
			}
			b=b>>1;
		}
	}
	sort(a+1,a+n+1,cmp);
	for(int i=31;i>=1;i--){
		if(maxm[i]>=m){
			k=i;break;
		}
	}
	zz=n+1;
	for(int i=1;i<=n;i++){
		if(a[i].d<k){
			zz=i;break;
		}
		b=a[i].s;
		for(int j=1;j<=k;j++){
			if(b%2==1)qz[i][j]=1;
			b=b>>1;
		}
	}
	long long l=kkk[k-1],r=kkk[k]-1,mid;
	while(l<r){
		mid=((l+r)>>1)+1;
		if(chk(mid)){
			l=mid;
		}
		else r=mid-1;
	}
	printf("%lld",l);
	return 0;
}