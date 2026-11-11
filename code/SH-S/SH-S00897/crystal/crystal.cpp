#include<bits/stdc++.h>
using namespace std;
const int SIZE=5e5+9;
void read(long long &x){
	x^=x;
	int f=1;
	char a=getchar();
	while(!('0'<=a&&a<='9')){
		if(a=='-')f=-1;
		a=getchar();
	}
	while('0'<=a&&a<='9'){
		x=x*10+a-'0';
		a=getchar();
	}
	x*=f;
	return ;
}

long long n,m,ans=1;
long long a[SIZE],d[SIZE];

bool check(long long x,long long u){
	long long num=x-u,sum=d[x-1]-d[u-1];
	if(num*a[x]-sum<=m)return 1;
	else return 0;
}

int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	read(n);
	read(m);
	long long i;
	long long l,r,mid;
	for(i=1;i<=n;i++)read(a[i]);
	sort(a+1,a+1+n);
	for(i=1;i<=n;i++)d[i]=d[i-1]+a[i];
	for(i=1;i<=n;i++){
		l=1,r=i-1;
		while(l<r){
			mid=(l+r)>>1;
			if(check(i,mid))r=mid;
			else l=mid+1;
		}
		ans=max(ans,i-r+1);
	}
	printf("%lld\n",ans);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
