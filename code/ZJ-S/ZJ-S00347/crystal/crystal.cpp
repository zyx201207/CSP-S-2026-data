#include<bits/stdc++.h>
using namespace std;
long long ans,n,m,a[500050],b[500050];
inline long long rd(){
	long long x=0,f=1;char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()){
		if(ch=='-')f=-1;
	}
	for(;ch>='0'&&ch<='9';ch=getchar())x=(x<<1)+(x<<3)+(ch^48);
	return f*x;
}
int main(){
	freopen("crystal.in","r",stdin);
	freopen("crystal.out","w",stdout);
	n=rd();
	m=rd();
	b[0]=0;
	for(long long i=1;i<=n;i++){
		a[i]=rd();
	}
	sort(a+1,a+1+n);
	for(long long i=1;i<=n;i++){
		b[i]=b[i-1]+a[i];
	}
	ans=0;
	for(long long l=1,r=1;l<=n;l++){
		if(r<l)r=l;
		while(a[r+1]*(r-l+2)-(b[r+1]-b[l-1])<=m&&r<n)r++;
		ans=max(ans,r-l+1);
	}
	cout<<ans;
	return 0;
}