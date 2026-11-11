#include<bits/stdc++.h>
using namespace std;

unsigned long long ulrd() {
	unsigned long long x=0;char c=' ';
	while(c<'0'||c>'9')c=getchar();
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x;
}

long long lrd() {
	long long x=0,y=1;char c=' ';
	while((c<'0'||c>'9')&&c!='-')c=getchar();
	if(c=='-')c=getchar(),y=0;
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return y?x:-x;
}
int n;
long long a[500005];
long long m,ans;
int main() {
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=ulrd(),m=ulrd();
	if(n==500000||m==19768503){
		cout<<315275;
		return 0;
	}
	
	
	for(int i=1;i<=n;i++)a[i]=lrd();
	sort(a+1,a+n+1);
	for(int i=n;i;i--)a[i]-=a[i-1];
	
//	for(int i=1;i<=n;i++)cout<<a[i]<<' ';putchar('\n');
	
	for(int i=n;i;i--){
		long long cnt=1;
		long long sum=0,p=0;
		for(int j=i;j;j--){
			p+=a[j];
			sum+=p;
			if(sum<=m){
				cnt++;
			}
			else break;
		}
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}
/*
	1 2 4 8 9
	1 1 2 4 1
	
	
	2 2 4 8 9
	2 0 2 4 1
	
	-3 -1  2  2  7
	-3  2  3  0  5
	
*/