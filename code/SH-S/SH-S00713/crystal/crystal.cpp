#include<bits/stdc++.h>
using namespace std;
#define int long long
inline int read(){
	char ch=getchar();
	int op=1,x=0;
	while(ch<'0'||ch>'9'){
		if(ch=='-'){
			op=-1;
		}
		ch=getchar();
	}
	while('0'<=ch&&ch<='9'){
		x=x*10+ch-'0';
		ch=getchar();
	}
	return op*x;
}
const int N=5e5+9;
int n,m,a[N],cnt,ans;
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read();
	m=read();
	for(int i=1;i<=n;i++){
		a[i]=read();
	}
	sort(a+1,a+1+n);
	int l=1;
	for(int i=2;i<=n;i++){
		cnt=cnt+(a[i]-a[i-1])*(i-l);
		while(cnt>m){
			cnt=cnt-(a[i]-a[l]);
			l++;
		}
		ans=max(ans,i-l+1);
	}
	cout<<ans<<endl;
	return 0;
}
/*
5 5
1 2 4 8 9



2 2 4 8 9






1 2 4 1



nlogn

f[n]=f[n-1]




*/
