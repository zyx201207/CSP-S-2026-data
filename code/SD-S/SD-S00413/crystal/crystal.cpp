#include<bits/stdc++.h>
using namespace std;
#define int long long
using ii=__int128;

int read(){
	int s=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		s=s*10+c-'0';
		c=getchar();
	}
	return s*f;
} 
const int N=5e5+5;
int n,m;
int a[N];

signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	for(int i=1;i<=n;i++)a[i]=read();
	sort(a+1,a+1+n);
	ii sum=0;
	int ans=1,p=1;
	for(int i=2;i<=n;i++){
		sum+=(ii)(i-p)*(a[i]-a[i-1]);
		while(p<i&&sum>m){
			sum-=a[i]-a[p];
			p++;
		}
		ans=max(ans,i-p+1);
	}
	printf("%lld\n",ans);
	
	
	return 0;
}

/*
5 5
1 2 4 8 9

3

5 8
-3 -1 2 2 7

4

*/
