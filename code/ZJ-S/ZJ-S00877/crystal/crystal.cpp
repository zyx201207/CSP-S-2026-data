#include<bits/stdc++.h>
#define int long long
#define FL(i,a,b) for(int i=(a);i<=(b);i++)
using namespace std;
inline int read(){
	int sum=0,f=1;char c=getchar();
	while(!isdigit(c)){if(c=='-') f=-f;c=getchar();}
	while(isdigit(c)){sum=sum*10+c-'0';c=getchar();}
	return sum*f;
}
const int N=5e5+5;
int n,m,ans=1;
int a[N];
signed main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=read(),m=read();
	FL(i,1,n) a[i]=read();
	sort(a+1,a+n+1);
	int j=1,cnt=0,sum=0;
	FL(i,2,n){
		if(a[i-1]!=a[i]){
			int k=i-1;
			while(k>=1&&a[k]==a[i-1]) cnt++,k--;
			sum+=cnt*(a[i]-a[i-1]);
		}
		while(sum>m){
			cnt--;
			sum-=(a[i]-a[j]);
			j++;
		}
		ans=max(ans,i-j+1);
	}
	cout<<ans;
	return 0;
}
