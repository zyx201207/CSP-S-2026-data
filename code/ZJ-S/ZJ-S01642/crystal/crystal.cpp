#include<bits/stdc++.h>
using namespace std;
int n;
long long m;
long long read(){
	char c=getchar();
	long long res=0;
	short f=1;
	while(c<'0' || c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0' && c<='9'){
		res=res*10+c-'0';
		c=getchar();
	}
	return f*res;
}
void write(long long x){
	if(x<0){putchar('-');x=-x;}
	if(x>=10)write(x/10);
	putchar(x%10+'0');
}
long long a[500005];
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+n+1);
	int j=n,sum=0,ans=0;
	for(int i=n;i>=1;i--){
		while(j>1 && sum+a[i]-a[j-1]<=m){
			j--;
			sum+=a[i]-a[j];
		}
		//cout<<j<<" "<<i<<" "<<sum<<endl;
		ans=max(ans,i-j+1);
		sum-=(i-j)*(a[i]-a[i-1]);
	}
	write(ans);
	return 0;
}
