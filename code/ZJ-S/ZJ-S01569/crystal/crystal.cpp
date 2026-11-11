#include <bits/stdc++.h>
using namespace std;
long long n,flog,fl;
long long m,u,op,a[500005],t,w,mid;
//inline int read(){
//	int x=0,gl=0;
//	char c=getchar();
//	while(c<'0'||c>'9'){ if(c=='-') gl=1;c=getchar();}
//	while(c>='0'&&c<='9') x=x*10+(c-'0'),c=getchar();
//	return gl?-x:x;
//}
void check(int x){
	long long b[500005],k=m,sl=0;
	for(int i=1;i<=n;i++)
		b[i]=x-a[i];
	for(int i=1;i<=n;i++)
		if(b[i]>=0)
			if(k-b[i]>=0)
				k-=b[i],sl++;
	if(sl>=op){ op=sl;}
}
void tyh(){
	long long x=0,kl=1,s=0;
	while(s<=m){
		s+=kl;
		kl++;
		x++;
	}
	if(s==m) x++;
	if(x==n+1) x--;
	cout<<min(x,n);
}
void TYH(){
	long long x=0,kl=u,s=0;
	while(s<=m){
		s+=kl;
		x++;
		kl*=2;
		if(kl==0){
			x=n;
			break;
		}
		
	}
	if(x==n+1)x--;
	cout<<min(x,n);
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		if(a[i]!=i) flog=1;
	if(!flog){
		tyh();
		return 0;
	}
	sort(a+1,a+1+n);
	u=a[2]-a[1];
	for(int i=3;i<=n;i++)
		if(a[i]-a[i-1]!=u) fl=1;
	if(!fl){
		TYH();
		return 0;
	}
	for(int i=1;i<=n;i++)
		check(a[i]);
//	t=1;w=n;
//	while(t<=w){
//		mid=(t+w)>>1;
//		if(check(a[t])) w=mid-1;
//		else t=mid+1;
//	}
	cout<<op;
	return 0;
}
/*
5 5
1 2 4 8 9
long long
*/