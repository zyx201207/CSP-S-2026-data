#include<bits/stdc++.h>
using namespace std;
const int MA=500005;
int n,m,a[MA],last[MA],ans[MA];
int read()
{
	int f=1,x=0;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) if(ch=='-') f=-1;
	for(;ch>='0'&&ch<='9';ch=getchar()) x=x*10+ch-'0';
	return f*x;
}
int main()
{
	freopen("card.in","r",stdin);
	freopen("card.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	for(int i=n;i>=1;i--){
		if(!last[a[i]]){
			last[a[i]]=i;
		}
	}
	for(int i=1;i<=n;i++){
		int po=i;
		while(po<=n){
			ans[a[po]]++;
			po=last[a[po]]+1;
		}
	}
	for(int i=1;i<=m;i++){
		printf("%d ",ans[i]);
	}
}
