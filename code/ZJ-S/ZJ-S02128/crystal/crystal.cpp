#include <iostream>
#include <bits/stdc++.h>
using namespace std;
long long n,ans=0,s,d;
double s1;
bool flag1=1,flag2=1;
long long m,a[500005],b[500005],sum,dj=2;
long long read(){
	long long nov=1,dat=0;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-') nov=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		dat=(dat<<3)+(dat<<1)+(c&15);
		c=getchar();
	}
	return nov*dat;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	s1=m;
	for(int i=1;i<=n;i++){
		a[i]=read();
		if(a[i]!=i) flag1=0;
	} 
	//a[i]=i
	if(flag1==1){
		s=int(sqrt(s1*2));
		ans=s+1;
		cout<<ans;
		return 0;
	}
	
	sort(a+1,a+n+1);
	d=a[2]-a[1];
	b[1]=0;
	for(int i=2;i<=n;i++){
		b[i]=a[i]-a[i-1];
		if(b[i]!=d) flag2=0;
	}
	//等差数列
	if(flag2==1){
		s=int(sqrt(s1*2/d));
		ans=s+1;
		cout<<ans;
		return 0;
	}
	//普通情况
	a[0]=a[1];
	for(long long i=1;i<=n;i++){
		m+=a[dj-1]-a[i-1];
		for(long long j=dj;j<=n;j++){
			if( m >= (j-i)*b[j] ) m-=(j-i)*b[j];
			else{
				ans=max(ans,j-i);
				dj=j;
				break;
			}
		}
	}
	cout<<ans;
	return 0;
}